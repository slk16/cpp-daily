#include <iostream>
#include <random>
#include <algorithm>

using namespace std;
#define TC_END "\033[0m"
#define TC_RED "\033[1;31m"
#define TC_GRN "\033[1;32m"
#define TC_YLW "\033[1;33m"
#define TC_BLU "\033[1;34m"

// test() :
int create_random_number();
void print(vector<int>& nums);
void __test();
void pv(vector<int>& v);
// sort() : 
void bubble_sort(vector<int>& nums);
void shell_sort(vector<int>& nums);
void insertion_sort(vector<int>& nums);
void insertion_sort2(vector<int>& nums);
// ----------------------------

#define test1 0
#define test2 0

int main()
{
#if test1
    vector<int> v {2,1,5,4,6,5,7};
    std::sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << " ";
    }
#endif
//    for (int i = 0; i < 10; ++i)
//    {
//        cout << create_random_number() << " " << endl;
//    }

    __test();

#if test2
    vector<int> nums{3,4,5,2,1,0, 10,22,654, 777};
    shell_sort(nums);
    for (int i : nums)
    {
        cout << i << " " ;
    }
    cout << endl;
#endif



    return 0;
}
// The sort code
int __partition(vector<int>& nums, int left, int right)
{
    int pivot = left;
    int i = left + 1;
    while ()
}

void quick_sort(vector<int>& nums)
{
    




}

void __merge(vector<int>& nums, int left, int right, int mid)
{
    vector<int> help(right - left + 1);
    int i = left;
    int j = mid + 1;
    int n = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            help[n++] = nums[i++];
        else
            help[n++] = nums[j++];
    }
    while (i <= mid)
        help[n++] = nums[i++];
    while (j <= right)
        help[n++] = nums[j++];
    for (int w = 0; w < right - left + 1; ++w) {
        nums[left + w] = help[w];
    }
}

void __merge_sort(vector<int>& nums, int left, int right)
{
    if (right == left)
        return;
    else if (right - left == 1)
    {
        if (nums[left] > nums[right])
            swap(nums[left],nums[right]);
        return;
    }
    int mid;
    mid = ((right - left) >> 1) + left;/// 一定要记得移位运算符优先级比加法运算符优先级要低！！！！
    __merge_sort(nums, left, mid);
    __merge_sort(nums, mid + 1, right);
    __merge(nums,left, right, mid);
}

void merge_sort(vector<int>& nums)
{
    __merge_sort(nums, 0, nums.size() - 1);
}

void selection_sort(vector<int>& nums)
{
    int mi;
    if (nums.size() < 2)
        return;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        mi = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[mi])
            {
                mi = j;
            }
        }
        swap(nums[mi], nums[i]);
    }

}

void insertion_sort(vector<int>& nums)
{
    if (nums.size() < 2) // 2 4 2 6 3 7
        return;·
    for (int i = 1; i < nums.size(); ++i) {
        int temp = nums[i];
        if (temp >= nums[i - 1])
            continue;
        int j = i - 1;
        while (j >= 0 && nums[j] > temp) {
            j--;
        }
        for (int w = i; w > j + 1; --w) {
            nums[w] = nums[w - 1];
        }
        nums[j + 1] = temp;
    }
}
void shell_sort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = len >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < len; ++i) {
            int temp = nums[i],j;
            for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap)
                nums[j + gap] = nums[j];
            nums[j + gap] = temp;   
        }
    }
}
void insertion_sort2(vector<int>& nums)
{
    int i,j;
    int len = nums.size();
    if (len < 2)
        return;
    for (i = 1; i < len; ++i) {
        int temp = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > temp; --j) 
            nums[j + 1] = nums[j];
        nums[j + 1] = temp;
    }
}

void bubble_sort(vector<int>& nums)
{
    if (nums.size() < 2)
        return;
    for (int i = nums.size() - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}


// The test code


void __test(){
    bool flag_end = true;
    vector<vector<int>> error;
    for (int i = 0; i < 300; ++i) {
        cout << "test " << i + 1 << " ";
        size_t size; 
        bool flag = true;
        size = create_random_number() % 10001;
        vector<int> arr1(size);
        for (int j = 0; j < size; ++j) {
            arr1[j] = create_random_number();
        }
        vector<int> arr2(arr1);
        // -----------------------------------------
        //   Here is the function call

        //bubble_sort(arr1);
        //insertion_sort(arr1);
        //selection_sort(arr1);
        //shell_sort(arr1);
        //insertion_sort(arr1);
        merge_sort(arr1);

        //std::sort(arr1.begin(),arr1.end());

        std::sort(arr2.begin(), arr2.end());

        //print(arr1);
        //cout << endl << endl;
        //print(arr2);


        //   Check %arr1 and %arr2
        // -----------------------------------------
        for (int i = 0; i < size; ++i) {
            if (arr1[i] != arr2[i]) {
                flag = false;
            }
        }
        if (flag)
            cout << TC_GRN << "True" << TC_END << "\n";
        else {
            cout << TC_RED << "False" << TC_END "\n";
            error.push_back(arr1);
            flag_end = false;
        }
    }
    cout << TC_YLW << "Test Result : " << TC_END << "\n" << "\n";
    if (flag_end) cout << TC_GRN << "all test complete, no error occur" << TC_END << "\n";
    else { cout << TC_RED << "error occur !!!" << TC_END << "\n"; }
    cout << endl;
}

int create_random_number() {
    static std::default_random_engine e(std::random_device{}());
    static std::uniform_int_distribution u(0,65535);
    return u(e);
}


void print(vector<int>& nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
}
void pv(vector<int>& v)
{
    std::cout << TC_YLW << "std vector of length " << v.size() << " = { " << TC_END;
    for (int i : v)
        cout << i << " ";
    cout << TC_YLW << " }" << TC_END << endl;
}

void pv(vector<int>& v, unsigned int size)
{
    std::cout << TC_YLW << "std vector of length " << v.size() << " = { " << TC_END;
    for (int i = 0; i < size; ++i)
        cout << v[i] << " ";
    cout << TC_YLW << " }" << TC_END << endl;
}

void pv(vector<int>& v, int begin, int end)
{
    std::cout << TC_YLW << "std vector of length " << v.size() << " = { " << TC_END;
    for (int i = begin; i <= end; ++i)
        cout << v[i] << " ";
    cout << TC_YLW << " }" << TC_END << endl;
}
