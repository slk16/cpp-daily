	.file	"day20260822.cpp"
	.text
#APP
	.globl std::ios_base_library_init()
#NO_APP
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,std::ctype<char>::do_widen(char) const,comdat
	.align 2
	.p2align 4
	.weak	std::ctype<char>::do_widen(char) const
	.type	std::ctype<char>::do_widen(char) const, @function
std::ctype<char>::do_widen(char) const:
.LFB1810:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1810:
	.size	std::ctype<char>::do_widen(char) const, .-std::ctype<char>::do_widen(char) const
	.text
	.p2align 4
	.globl	test::test01()
	.type	test::test01(), @function
test::test01():
.LFB2190:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$20, %esi
	leaq	std::cout(%rip), %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	std::basic_ostream<char, std::char_traits<char> >::operator<<(int)@PLT
	movq	%rax, %rbx
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %rbp
	testq	%rbp, %rbp
	je	.L9
	cmpb	$0, 56(%rbp)
	je	.L5
	movsbl	67(%rbp), %esi
.L6:
	movq	%rbx, %rdi
	call	std::basic_ostream<char, std::char_traits<char> >::put(char)@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	movq	%rax, %rdi
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	std::basic_ostream<char, std::char_traits<char> >::flush()@PLT
	.p2align 4,,10
	.p2align 3
.L5:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	std::ctype<char>::_M_widen_init() const@PLT
	movq	0(%rbp), %rax
	movl	$10, %esi
	leaq	std::ctype<char>::do_widen(char) const(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L6
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L6
.L9:
	call	std::__throw_bad_cast()@PLT
	.cfi_endproc
.LFE2190:
	.size	test::test01(), .-test::test01()
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2191:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	test::test01()
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2191:
	.size	main, .-main
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"./subtitles"
.LC1:
	.string	"content"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4
	.globl	test::extract::extract()
	.type	test::extract::extract(), @function
test::extract::extract():
.LFB2188:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2188
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$616, %rsp
	.cfi_def_cfa_offset 672
	movq	%fs:40, %rax
	movq	%rax, 600(%rsp)
	xorl	%eax, %eax
	leaq	48(%rsp), %rax
	leaq	64(%rsp), %rbx
	movq	$0, 40(%rsp)
	movq	%rax, 24(%rsp)
	movq	%rax, 32(%rsp)
	leaq	328(%rsp), %rax
	movq	%rax, %rdi
	movq	%rbx, 16(%rsp)
	movq	%rax, (%rsp)
	movb	$0, 48(%rsp)
	call	std::ios_base::ios_base()@PLT
	movq	16+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %r14
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	leaq	16+vtable for std::basic_ios<char, std::char_traits<char> >(%rip), %rax
	pxor	%xmm0, %xmm0
	movw	%cx, 552(%rsp)
	movq	24+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movaps	%xmm0, 560(%rsp)
	movaps	%xmm0, 576(%rsp)
	movq	%rax, 328(%rsp)
	movq	-24(%r14), %rax
	movq	$0, 544(%rsp)
	movq	%r14, 64(%rsp)
	movq	%rcx, 64(%rsp,%rax)
	movq	$0, 72(%rsp)
	addq	-24(%r14), %rbx
	movq	%rbx, %rdi
.LEHB0:
	call	std::basic_ios<char, std::char_traits<char> >::init(std::basic_streambuf<char, std::char_traits<char> >*)@PLT
.LEHE0:
	movq	32+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	xorl	%esi, %esi
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	leaq	80(%rsp,%rax), %rdi
	movq	40+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	%rax, (%rdi)
.LEHB1:
	call	std::basic_ios<char, std::char_traits<char> >::init(std::basic_streambuf<char, std::char_traits<char> >*)@PLT
.LEHE1:
	movq	8+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	48+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	-24(%rax), %rax
	movq	%rcx, 64(%rsp,%rax)
	leaq	24+vtable for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	%rax, 64(%rsp)
	addq	$80, %rax
	movq	%rax, 328(%rsp)
	subq	$40, %rax
	movq	%rax, 80(%rsp)
	leaq	88(%rsp), %rax
	movq	%rax, %rdi
	movq	%rax, 8(%rsp)
.LEHB2:
	call	std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf()@PLT
.LEHE2:
	movq	8(%rsp), %rbx
	movq	(%rsp), %rdi
	movq	%rbx, %rsi
.LEHB3:
	call	std::basic_ios<char, std::char_traits<char> >::init(std::basic_streambuf<char, std::char_traits<char> >*)@PLT
	movl	$24, %edx
	leaq	.LC0(%rip), %rsi
	movq	%rbx, %rdi
	call	std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode)@PLT
	movq	64(%rsp), %rdx
	movq	16(%rsp), %rdi
	addq	-24(%rdx), %rdi
	testq	%rax, %rax
	je	.L49
	xorl	%esi, %esi
	call	std::basic_ios<char, std::char_traits<char> >::clear(std::_Ios_Iostate)@PLT
.LEHE3:
.L19:
	movq	std::cin(%rip), %rax
	leaq	std::cin(%rip), %rbp
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L23
	leaq	32(%rsp), %r12
	leaq	std::ctype<char>::do_widen(char) const(%rip), %r15
	leaq	.LC1(%rip), %r13
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L51:
	movsbl	67(%rbx), %edx
.L25:
	movq	%r12, %rsi
	movq	%rbp, %rdi
.LEHB4:
	call	std::basic_istream<char, std::char_traits<char> >& std::getline<char, std::char_traits<char>, std::allocator<char> >(std::basic_istream<char, std::char_traits<char> >&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, char)@PLT
	movq	(%rax), %rdx
	movq	-24(%rdx), %rdx
	testb	$5, 32(%rax,%rdx)
	jne	.L50
	movl	$7, %ecx
	xorl	%edx, %edx
	movq	%r13, %rsi
	movq	%r12, %rdi
	call	std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::find_first_of(char const*, unsigned long, unsigned long) const@PLT
	movq	0(%rbp), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L23
.L17:
	cmpb	$0, 56(%rbx)
	jne	.L51
	movq	%rbx, %rdi
	call	std::ctype<char>::_M_widen_init() const@PLT
	movq	(%rbx), %rax
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	%r15, %rax
	je	.L25
	movl	$10, %esi
	movq	%rbx, %rdi
	call	*%rax
.LEHE4:
	movsbl	%al, %edx
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L50:
	leaq	24+vtable for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	8(%rsp), %rdi
	movq	.LC2(%rip), %xmm0
	movq	%rax, 64(%rsp)
	addq	$80, %rax
	movq	%rax, 328(%rsp)
	leaq	16+vtable for std::basic_filebuf<char, std::char_traits<char> >(%rip), %rax
	movq	%rax, %xmm1
	punpcklqdq	%xmm1, %xmm0
	movaps	%xmm0, 80(%rsp)
.LEHB5:
	call	std::basic_filebuf<char, std::char_traits<char> >::close()@PLT
.LEHE5:
.L30:
	leaq	192(%rsp), %rdi
	call	std::__basic_file<char>::~__basic_file()@PLT
	leaq	16+vtable for std::basic_streambuf<char, std::char_traits<char> >(%rip), %rax
	leaq	144(%rsp), %rdi
	movq	%rax, 88(%rsp)
	call	std::locale::~locale()@PLT
	movq	8+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	48+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	(%rsp), %rdi
	movq	-24(%rax), %rax
	movq	%rcx, 64(%rsp,%rax)
	movq	32+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	40+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	movq	%rcx, 80(%rsp,%rax)
	movq	-24(%r14), %rax
	movq	24+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	%r14, 64(%rsp)
	movq	%rcx, 64(%rsp,%rax)
	leaq	16+vtable for std::basic_ios<char, std::char_traits<char> >(%rip), %rax
	movq	%rax, 328(%rsp)
	movq	$0, 72(%rsp)
	call	std::ios_base::~ios_base()@PLT
	movq	32(%rsp), %rdi
	movq	24(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L12
	movq	48(%rsp), %rax
	leaq	1(%rax), %rsi
	call	operator delete(void*, unsigned long)@PLT
.L12:
	movq	600(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L48
	addq	$616, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	.cfi_restore_state
	movl	32(%rdi), %esi
	orl	$4, %esi
.LEHB6:
	call	std::basic_ios<char, std::char_traits<char> >::clear(std::_Ios_Iostate)@PLT
.LEHE6:
	jmp	.L19
.L23:
	movq	600(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L48
	leaq	32(%rsp), %r12
.LEHB7:
	call	std::__throw_bad_cast()@PLT
.LEHE7:
.L48:
	call	__stack_chk_fail@PLT
.L38:
	endbr64
	movq	%rax, %rbx
	jmp	.L20
.L35:
	endbr64
	movq	%rax, %rbx
	jmp	.L31
.L40:
	endbr64
	movq	%rax, %rdi
	jmp	.L29
.L39:
	endbr64
	movq	%rax, %rbx
	jmp	.L14
.L36:
	endbr64
	movq	%rax, %rbx
	jmp	.L15
.L37:
	endbr64
	movq	%rax, %rbx
	jmp	.L21
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
	.align 4
.LLSDA2188:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT2188-.LLSDATTD2188
.LLSDATTD2188:
	.byte	0x1
	.uleb128 .LLSDACSE2188-.LLSDACSB2188
.LLSDACSB2188:
	.uleb128 .LEHB0-.LFB2188
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L36-.LFB2188
	.uleb128 0
	.uleb128 .LEHB1-.LFB2188
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L39-.LFB2188
	.uleb128 0
	.uleb128 .LEHB2-.LFB2188
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L37-.LFB2188
	.uleb128 0
	.uleb128 .LEHB3-.LFB2188
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L38-.LFB2188
	.uleb128 0
	.uleb128 .LEHB4-.LFB2188
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L35-.LFB2188
	.uleb128 0
	.uleb128 .LEHB5-.LFB2188
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L40-.LFB2188
	.uleb128 0x1
	.uleb128 .LEHB6-.LFB2188
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L38-.LFB2188
	.uleb128 0
	.uleb128 .LEHB7-.LFB2188
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L35-.LFB2188
	.uleb128 0
.LLSDACSE2188:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT2188:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC2188
	.type	test::extract::extract() [clone .cold], @function
test::extract::extract() [clone .cold]:
.LFSB2188:
.L20:
	.cfi_def_cfa_offset 672
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	8(%rsp), %rdi
	call	std::basic_filebuf<char, std::char_traits<char> >::~basic_filebuf()@PLT
.L21:
	movq	8+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	48+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	-24(%rax), %rax
	movq	%rcx, 64(%rsp,%rax)
	movq	32+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rax
	movq	40+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	%rax, 80(%rsp)
	movq	-24(%rax), %rax
	movq	%rcx, 80(%rsp,%rax)
	movq	-24(%r14), %rax
	movq	24+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	movq	%r14, 64(%rsp)
	movq	%rcx, 64(%rsp,%rax)
	xorl	%eax, %eax
	movq	%rax, 72(%rsp)
.L15:
	movq	(%rsp), %rdi
	leaq	16+vtable for std::basic_ios<char, std::char_traits<char> >(%rip), %rax
	leaq	32(%rsp), %r12
	movq	%rax, 328(%rsp)
	call	std::ios_base::~ios_base()@PLT
	jmp	.L22
.L31:
	movq	16(%rsp), %rdi
	call	std::basic_fstream<char, std::char_traits<char> >::~basic_fstream()@PLT
.L22:
	movq	%r12, %rdi
	call	std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_dispose()@PLT
	movq	600(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L52
	movq	%rbx, %rdi
.LEHB8:
	call	_Unwind_Resume@PLT
.LEHE8:
.L52:
	call	__stack_chk_fail@PLT
.L29:
	call	__cxa_begin_catch@PLT
	call	__cxa_end_catch@PLT
	jmp	.L30
.L14:
	movq	-24(%r14), %rax
	movq	24+VTT for std::basic_fstream<char, std::char_traits<char> >(%rip), %rcx
	xorl	%edx, %edx
	movq	%r14, 64(%rsp)
	movq	%rcx, 64(%rsp,%rax)
	movq	%rdx, 72(%rsp)
	jmp	.L15
	.cfi_endproc
.LFE2188:
	.section	.gcc_except_table
	.align 4
.LLSDAC2188:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATTC2188-.LLSDATTDC2188
.LLSDATTDC2188:
	.byte	0x1
	.uleb128 .LLSDACSEC2188-.LLSDACSBC2188
.LLSDACSBC2188:
	.uleb128 .LEHB8-.LCOLDB3
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSEC2188:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATTC2188:
	.section	.text.unlikely
	.text
	.size	test::extract::extract(), .-test::extract::extract()
	.section	.text.unlikely
	.size	test::extract::extract() [clone .cold], .-test::extract::extract() [clone .cold]
.LCOLDE3:
	.text
.LHOTE3:
	.section	.data.rel.ro,"aw"
	.align 8
.LC2:
	.quad	vtable for std::basic_fstream<char, std::char_traits<char> >+64
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
