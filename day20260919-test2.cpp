// day20260919.cpp
// 红黑树（Red-Black Tree）手写实现 + 性质校验器 + 随机压力测试
//
// 编译： g++ -std=c++17 -O2 -Wall -Wextra day20260919-test2.cpp -o rbtree && ./rbtree
//
// 结构：
//   1. RBTree     —— CLRS 风格实现（共享哨兵 NIL），insert / erase / find
//   2. validate() —— 把红黑树 5 条性质写成代码，随时自检
//   3. main()     —— 小样例打印 + 与 std::set 对拍的随机压力测试
//
// 学习建议：先读 validate()，再读 insert / erase。理解"我们要维持什么"，
//           比记住"代码怎么写"重要得多。

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

namespace rbt {

enum Color { RED, BLACK };

struct Node {
    int   key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k, Color c, Node* nil) : key(k), color(c), left(nil), right(nil), parent(nil) {}
};

class RBTree {
public:
    RBTree() {
        nil_ = new Node(0, BLACK, nullptr);
        nil_->left = nil_->right = nil_->parent = nil_;  // 自环哨兵
        root_ = nil_;
        size_ = 0;
    }

    ~RBTree() {
        destroy(root_);
        delete nil_;
    }

    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;

    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    // ---------------------------------------------------------------
    // 查找
    // ---------------------------------------------------------------
    bool contains(int key) const { return find(key) != nil_; }

    Node* find(int key) const {
        Node* x = root_;
        while (x != nil_) {
            if (key < x->key)
                x = x->left;
            else if (key > x->key)
                x = x->right;
            else
                return x;
        }
        return nil_;
    }

    int minimum() const { return minimum(root_)->key; }
    int maximum() const { return maximum(root_)->key; }

    // 中序遍历，结果应是严格递增序列（同时用来和 std::set 对拍）
    std::vector<int> inorder() const {
        std::vector<int> out;
        out.reserve(size_);
        inorder_impl(root_, out);
        return out;
    }

    // ---------------------------------------------------------------
    // 插入
    // ---------------------------------------------------------------
    void insert(int key) {
        Node* z = new Node(key, RED, nil_);  // 新节点一律先染红
        Node* y = nil_;                // y 将记录 z 的父节点
        Node* x = root_;
        while (x != nil_) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else if (z->key > x->key)
                x = x->right;
            else {
                delete z;  // 重复键：忽略
                return;
            }
        }

        z->parent = y;
        if (y == nil_)
            root_ = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;

        ++size_;
        insert_fixup(z);
    }

    // ---------------------------------------------------------------
    // 删除
    // ---------------------------------------------------------------
    bool erase(int key) {
        Node* z = find(key);
        if (z == nil_)
            return false;

        Node* y = z;                       // y 是真正被物理摘除的节点
        Color y_original = y->color;
        Node* x = nil_;                    // x 顶替 y 的位置，可能背负"额外黑"

        if (z->left == nil_) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil_) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);         // 后继
            y_original = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;             // 即使 x 是哨兵也要设，修复时要用
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;           // 继承被删节点的颜色
        }

        delete z;
        --size_;

        // 摘掉的是黑节点 -> 某条路径黑高少 1，需要修复
        if (y_original == BLACK)
            erase_fixup(x);
        return true;
    }

    // ---------------------------------------------------------------
    // 校验器：把 5 条性质写成代码
    // ---------------------------------------------------------------
    bool validate(std::string* why = nullptr) const {
        auto fail = [&](const std::string& msg) {
            if (why) *why = msg;
            return false;
        };

        // 性质 3：哨兵必须是黑的
        if (nil_->color != BLACK)
            return fail("NIL sentinel is not black");

        if (root_ != nil_) {
            // 性质 2：根是黑的
            if (root_->color != BLACK)
                return fail("root is not black");
            // 根的父亲必须是哨兵
            if (root_->parent != nil_)
                return fail("root->parent != NIL");
        }

        // BST 有序性 + 中序严格递增
        std::vector<int> seq = inorder();
        for (std::size_t i = 1; i < seq.size(); ++i)
            if (!(seq[i - 1] < seq[i]))
                return fail("BST order violated (inorder not strictly increasing)");

        if (seq.size() != size_)
            return fail("size_ counter mismatch");

        // 性质 1/4/5 + 父子指针一致性，递归检查
        std::string inner;
        if (!check(root_, nil_, &inner))
            return fail(inner);

        return true;
    }

    std::size_t height() const { return height_impl(root_); }

    // 侧向打印（右子树在上，根在最左）：方便肉眼观察结构
    void dump(std::ostream& os) const { dump_impl(os, root_, 0); }

private:
    Node*       nil_;
    Node*       root_;
    std::size_t size_;

    // ---------------- 旋转 ----------------
    // 左旋：以 x 为支点，把 x 的右孩子 y 提上来
    void left_rotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;                       // y 的左子树过继给 x
        if (y->left != nil_)
            y->left->parent = x;

        y->parent = x->parent;                    // y 接管 x 的父亲
        if (x->parent == nil_)
            root_ = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;                              // x 降为 y 的左孩子
        x->parent = y;
    }

    // 右旋：与左旋镜像
    void right_rotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nil_)
            y->right->parent = x;

        y->parent = x->parent;
        if (x->parent == nil_)
            root_ = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    // ---------------- 插入修复 ----------------
    void insert_fixup(Node* z) {
        // 唯一可能违规的是"红红相邻"：z 红、z 的父亲也红
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;   // 叔叔

                if (y->color == RED) {
                    // Case 1：叔叔红 -> 变色 + 把违规上推
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // Case 2：叔叔黑，且 z 是"内侧"孩子 -> 先掰直
                    if (z == z->parent->right) {
                        z = z->parent;
                        left_rotate(z);
                    }
                    // Case 3：直线形状 -> 变色 + 旋转祖父
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
            } else {
                // 完全镜像
                Node* y = z->parent->parent->left;

                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        right_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    left_rotate(z->parent->parent);
                }
            }
        }
        root_->color = BLACK;  // 性质 2
    }

    // ---------------- 删除修复 ----------------
    // 入口时 x 身上背着一个"额外黑"（可能 x == nil_）
    void erase_fixup(Node* x) {
        while (x != root_ && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;           // 兄弟

                if (w->color == RED) {
                    // Case 1：兄弟红 -> 转成"兄弟黑"的情形
                    w->color = BLACK;
                    x->parent->color = RED;
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    // Case 2：兄弟黑，两个孩子都黑 -> 双黑上移，继续循环
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        // Case 3：近侄子红、远侄子黑 -> 转成 Case 4
                        w->left->color = BLACK;
                        w->color = RED;
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    // Case 4：远侄子红 -> 一次性解决，退出循环
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    left_rotate(x->parent);
                    x = root_;
                }
            } else {
                // 完全镜像
                Node* w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    right_rotate(x->parent);
                    x = root_;
                }
            }
        }
        x->color = BLACK;  // 吸收掉最后那个"额外黑"
    }

    // 用 v 顶替 u 的位置（v 可以是哨兵）
    void transplant(Node* u, Node* v) {
        if (u->parent == nil_)
            root_ = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    // ---------------- 辅助 ----------------
    Node* minimum(Node* x) const {
        while (x->left != nil_)
            x = x->left;
        return x;
    }

    Node* maximum(Node* x) const {
        while (x->right != nil_)
            x = x->right;
        return x;
    }

    void inorder_impl(Node* n, std::vector<int>& out) const {
        if (n == nil_)
            return;
        inorder_impl(n->left, out);
        out.push_back(n->key);
        inorder_impl(n->right, out);
    }

    void destroy(Node* n) {
        if (n == nil_)
            return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    std::size_t height_impl(Node* n) const {
        if (n == nil_)
            return 0;
        return 1 + std::max(height_impl(n->left), height_impl(n->right));
    }

    // 返回子树的黑高；违规时返回 -1（并把原因写入 why）
    int check(Node* n, Node* parent, std::string* why) const {
        if (n == nil_)
            return 1;  // 性质 3：NIL 自身算一个黑

        // 父子指针一致性
        if (n->parent != parent) {
            *why = "parent pointer broken at key " + std::to_string(n->key);
            return -1;
        }
        // 性质 4：红节点的孩子必须黑
        if (n->color == RED && (n->left->color == RED || n->right->color == RED)) {
            *why = "two consecutive reds at key " + std::to_string(n->key);
            return -1;
        }

        int lh = check(n->left, n, why);
        if (lh < 0)
            return -1;
        int rh = check(n->right, n, why);
        if (rh < 0)
            return -1;

        // 性质 5：左右黑高必须相等
        if (lh != rh) {
            *why = "black-height mismatch at key " + std::to_string(n->key) + " (left " +
                   std::to_string(lh) + ", right " + std::to_string(rh) + ")";
            return -1;
        }
        return lh + (n->color == BLACK ? 1 : 0);
    }

    void dump_impl(std::ostream& os, Node* n, int depth) const {
        if (n == nil_)
            return;
        dump_impl(os, n->right, depth + 1);
        os << std::string(static_cast<std::size_t>(depth) * 4, ' ') << n->key
           << (n->color == RED ? "(R)" : "(B)") << '\n';
        dump_impl(os, n->left, depth + 1);
    }
};

}  // namespace rbt

// ===================================================================
// 测试
// ===================================================================
namespace {

int g_checks = 0;
int g_failures = 0;

void expect(bool cond, const std::string& what) {
    ++g_checks;
    if (!cond) {
        ++g_failures;
        std::cout << "  [FAIL] " << what << '\n';
    }
}

// 每步操作后校验 + 与 std::set 对拍
void check_against(rbt::RBTree& t, const std::set<int>& ref, const std::string& ctx) {
    std::string why;
    if (!t.validate(&why)) {
        ++g_failures;
        std::cout << "  [INVARIANT BREAK] " << ctx << " -> " << why << '\n';
        return;
    }
    ++g_checks;
    std::vector<int> a = t.inorder();
    std::vector<int> b(ref.begin(), ref.end());
    if (a != b) {
        ++g_failures;
        std::cout << "  [MISMATCH] " << ctx << " size " << a.size() << " vs " << b.size() << '\n';
    }
}

void demo() {
    rbt::RBTree t;
    for (int k : {10, 20, 30, 15, 25, 5, 1}) {
        t.insert(k);
        std::cout << "insert " << k << "  (size=" << t.size() << ", height=" << t.height() << ")\n";
    }
    std::cout << "\n树结构（右子树在上、根在最左，缩进表示深度）：\n";
    t.dump(std::cout);

    std::cout << "\n中序: ";
    for (int k : t.inorder()) std::cout << k << ' ';
    std::cout << "\n\n依次删除 30 / 10 / 20：\n";
    for (int k : {30, 10, 20}) {
        t.erase(k);
        std::string why;
        bool ok = t.validate(&why);
        std::cout << "erase " << k << "  valid=" << (ok ? "yes" : "no") << "  (size=" << t.size()
                  << ", height=" << t.height() << ")\n";
        if (!ok) std::cout << "    -> " << why << '\n';
    }
    t.dump(std::cout);
}

// 随机压力测试：每次操作后都做完整校验
void stress(std::mt19937& rng, int rounds, int max_n) {
    std::cout << "\n压力测试: " << rounds << " 轮, n <= " << max_n << " ...\n";
    for (int r = 0; r < rounds; ++r) {
        int n = 1 + static_cast<int>(rng() % static_cast<unsigned>(max_n));
        std::vector<int> keys(n);
        for (int i = 0; i < n; ++i) keys[i] = i;

        // 打乱插入顺序
        std::shuffle(keys.begin(), keys.end(), rng);

        rbt::RBTree t;
        std::set<int> ref;
        for (int k : keys) {
            // 随机混入重复插入
            int v = (rng() % 8 == 0) ? keys[rng() % keys.size()] : k;
            t.insert(v);
            ref.insert(v);
            check_against(t, ref, "insert " + std::to_string(v));
        }

        // 随机删除
        std::shuffle(keys.begin(), keys.end(), rng);
        for (int k : keys) {
            if (rng() % 2 == 0) continue;  // 只删一半
            t.erase(k);
            ref.erase(k);
            check_against(t, ref, "erase " + std::to_string(k));
        }

        // 高度上界：h <= 2*log2(n+1)
        if (!ref.empty()) {
            double bound = 2.0 * std::log2(static_cast<double>(ref.size()) + 1.0);
            expect(static_cast<double>(t.height()) <= bound + 1e-9,
                   "height bound h <= 2*log2(n+1)");
        }
    }
}

// 有序插入（普通 BST 的最坏情况）不应退化成链
void sorted_insert_case() {
    const int N = 2000;
    rbt::RBTree t;
    for (int i = 0; i < N; ++i) t.insert(i);
    std::string why;
    expect(t.validate(&why), "sorted insert keeps RB invariants: " + why);
    double bound = 2.0 * std::log2(N + 1.0);
    std::cout << "\n顺序插入 " << N << " 个（普通 BST 会退化成链）:\n"
              << "  红黑树 height = " << t.height() << ", 上界 2*log2(n+1) = " << bound << '\n';
    expect(static_cast<double>(t.height()) <= bound + 1e-9, "sorted insert height bounded");
}

}  // namespace

int main() {
    std::cout << "=== 小样例 ===" << std::endl;
    demo();

    std::cout << "\n=== 顺序插入（最坏情况）===" << std::endl;
    sorted_insert_case();

    std::mt19937 rng(20260919);
    stress(rng, 300, 150);

    std::cout << "\n=== 结果 ===\n"
              << "checks = " << g_checks << ", failures = " << g_failures << '\n';
    return g_failures == 0 ? 0 : 1;
}
