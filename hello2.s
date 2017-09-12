
hello2:     file format elf64-x86-64


Disassembly of section .init:

00000000004003f0 <_init>:
_init():
  4003f0:	48 83 ec 08          	sub    $0x8,%rsp
  4003f4:	e8 63 00 00 00       	callq  40045c <call_gmon_start>
  4003f9:	48 83 c4 08          	add    $0x8,%rsp
  4003fd:	c3                   	retq   

Disassembly of section .plt:

0000000000400400 <puts@plt-0x10>:
  400400:	ff 35 ea 0b 20 00    	pushq  0x200bea(%rip)        # 600ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  400406:	ff 25 ec 0b 20 00    	jmpq   *0x200bec(%rip)        # 600ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  40040c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400410 <puts@plt>:
  400410:	ff 25 ea 0b 20 00    	jmpq   *0x200bea(%rip)        # 601000 <_GLOBAL_OFFSET_TABLE_+0x18>
  400416:	68 00 00 00 00       	pushq  $0x0
  40041b:	e9 e0 ff ff ff       	jmpq   400400 <_init+0x10>

0000000000400420 <__libc_start_main@plt>:
  400420:	ff 25 e2 0b 20 00    	jmpq   *0x200be2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x20>
  400426:	68 01 00 00 00       	pushq  $0x1
  40042b:	e9 d0 ff ff ff       	jmpq   400400 <_init+0x10>

Disassembly of section .text:

0000000000400430 <_start>:
_start():
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:65
  400430:	31 ed                	xor    %ebp,%ebp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:81
  400432:	49 89 d1             	mov    %rdx,%r9
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:83
  400435:	5e                   	pop    %rsi
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:84
  400436:	48 89 e2             	mov    %rsp,%rdx
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:86
  400439:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:88
  40043d:	50                   	push   %rax
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:92
  40043e:	54                   	push   %rsp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:106
  40043f:	49 c7 c0 f0 05 40 00 	mov    $0x4005f0,%r8
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:107
  400446:	48 c7 c1 60 05 40 00 	mov    $0x400560,%rcx
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:109
  40044d:	48 c7 c7 3c 05 40 00 	mov    $0x40053c,%rdi
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:113
  400454:	e8 c7 ff ff ff       	callq  400420 <__libc_start_main@plt>
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/../sysdeps/x86_64/elf/start.S:116
  400459:	f4                   	hlt    
  40045a:	90                   	nop
  40045b:	90                   	nop

000000000040045c <call_gmon_start>:
call_gmon_start():
  40045c:	48 83 ec 08          	sub    $0x8,%rsp
  400460:	48 8b 05 79 0b 20 00 	mov    0x200b79(%rip),%rax        # 600fe0 <_DYNAMIC+0x1e0>
  400467:	48 85 c0             	test   %rax,%rax
  40046a:	74 02                	je     40046e <call_gmon_start+0x12>
  40046c:	ff d0                	callq  *%rax
  40046e:	48 83 c4 08          	add    $0x8,%rsp
  400472:	c3                   	retq   
  400473:	90                   	nop
  400474:	90                   	nop
  400475:	90                   	nop
  400476:	90                   	nop
  400477:	90                   	nop
  400478:	90                   	nop
  400479:	90                   	nop
  40047a:	90                   	nop
  40047b:	90                   	nop
  40047c:	90                   	nop
  40047d:	90                   	nop
  40047e:	90                   	nop
  40047f:	90                   	nop

0000000000400480 <deregister_tm_clones>:
deregister_tm_clones():
  400480:	b8 27 10 60 00       	mov    $0x601027,%eax
  400485:	55                   	push   %rbp
  400486:	48 2d 20 10 60 00    	sub    $0x601020,%rax
  40048c:	48 83 f8 0e          	cmp    $0xe,%rax
  400490:	48 89 e5             	mov    %rsp,%rbp
  400493:	77 02                	ja     400497 <deregister_tm_clones+0x17>
  400495:	5d                   	pop    %rbp
  400496:	c3                   	retq   
  400497:	b8 00 00 00 00       	mov    $0x0,%eax
  40049c:	48 85 c0             	test   %rax,%rax
  40049f:	74 f4                	je     400495 <deregister_tm_clones+0x15>
  4004a1:	5d                   	pop    %rbp
  4004a2:	bf 20 10 60 00       	mov    $0x601020,%edi
  4004a7:	ff e0                	jmpq   *%rax
  4004a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004b0 <register_tm_clones>:
register_tm_clones():
  4004b0:	b8 20 10 60 00       	mov    $0x601020,%eax
  4004b5:	55                   	push   %rbp
  4004b6:	48 2d 20 10 60 00    	sub    $0x601020,%rax
  4004bc:	48 c1 f8 03          	sar    $0x3,%rax
  4004c0:	48 89 e5             	mov    %rsp,%rbp
  4004c3:	48 89 c2             	mov    %rax,%rdx
  4004c6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4004ca:	48 01 d0             	add    %rdx,%rax
  4004cd:	48 89 c6             	mov    %rax,%rsi
  4004d0:	48 d1 fe             	sar    %rsi
  4004d3:	75 02                	jne    4004d7 <register_tm_clones+0x27>
  4004d5:	5d                   	pop    %rbp
  4004d6:	c3                   	retq   
  4004d7:	ba 00 00 00 00       	mov    $0x0,%edx
  4004dc:	48 85 d2             	test   %rdx,%rdx
  4004df:	74 f4                	je     4004d5 <register_tm_clones+0x25>
  4004e1:	5d                   	pop    %rbp
  4004e2:	bf 20 10 60 00       	mov    $0x601020,%edi
  4004e7:	ff e2                	jmpq   *%rdx
  4004e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004f0 <__do_global_dtors_aux>:
__do_global_dtors_aux():
  4004f0:	80 3d 29 0b 20 00 00 	cmpb   $0x0,0x200b29(%rip)        # 601020 <__bss_start>
  4004f7:	75 11                	jne    40050a <__do_global_dtors_aux+0x1a>
  4004f9:	55                   	push   %rbp
  4004fa:	48 89 e5             	mov    %rsp,%rbp
  4004fd:	e8 7e ff ff ff       	callq  400480 <deregister_tm_clones>
  400502:	5d                   	pop    %rbp
  400503:	c6 05 16 0b 20 00 01 	movb   $0x1,0x200b16(%rip)        # 601020 <__bss_start>
  40050a:	f3 c3                	repz retq 
  40050c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400510 <frame_dummy>:
frame_dummy():
  400510:	48 83 3d e0 08 20 00 	cmpq   $0x0,0x2008e0(%rip)        # 600df8 <__JCR_END__>
  400517:	00 
  400518:	74 1b                	je     400535 <frame_dummy+0x25>
  40051a:	b8 00 00 00 00       	mov    $0x0,%eax
  40051f:	48 85 c0             	test   %rax,%rax
  400522:	74 11                	je     400535 <frame_dummy+0x25>
  400524:	55                   	push   %rbp
  400525:	bf f8 0d 60 00       	mov    $0x600df8,%edi
  40052a:	48 89 e5             	mov    %rsp,%rbp
  40052d:	ff d0                	callq  *%rax
  40052f:	5d                   	pop    %rbp
  400530:	e9 7b ff ff ff       	jmpq   4004b0 <register_tm_clones>
  400535:	e9 76 ff ff ff       	jmpq   4004b0 <register_tm_clones>
  40053a:	90                   	nop
  40053b:	90                   	nop

000000000040053c <main>:
main():
/Code/code_respo/c_cpp/hello.c:4
#include <stdio.h>

int main()
{
  40053c:	55                   	push   %rbp
  40053d:	48 89 e5             	mov    %rsp,%rbp
/Code/code_respo/c_cpp/hello.c:5
    printf("hello,world\n");
  400540:	bf 0c 06 40 00       	mov    $0x40060c,%edi
  400545:	e8 c6 fe ff ff       	callq  400410 <puts@plt>
/Code/code_respo/c_cpp/hello.c:7
    
    return 0;
  40054a:	b8 00 00 00 00       	mov    $0x0,%eax
/Code/code_respo/c_cpp/hello.c:9
	
}
  40054f:	5d                   	pop    %rbp
  400550:	c3                   	retq   
  400551:	90                   	nop
  400552:	90                   	nop
  400553:	90                   	nop
  400554:	90                   	nop
  400555:	90                   	nop
  400556:	90                   	nop
  400557:	90                   	nop
  400558:	90                   	nop
  400559:	90                   	nop
  40055a:	90                   	nop
  40055b:	90                   	nop
  40055c:	90                   	nop
  40055d:	90                   	nop
  40055e:	90                   	nop
  40055f:	90                   	nop

0000000000400560 <__libc_csu_init>:
__libc_csu_init():
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:107
  400560:	48 89 6c 24 d8       	mov    %rbp,-0x28(%rsp)
  400565:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:123
  40056a:	48 8d 2d 7f 08 20 00 	lea    0x20087f(%rip),%rbp        # 600df0 <__init_array_end>
  400571:	4c 8d 25 70 08 20 00 	lea    0x200870(%rip),%r12        # 600de8 <__frame_dummy_init_array_entry>
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:107
  400578:	48 89 5c 24 d0       	mov    %rbx,-0x30(%rsp)
  40057d:	4c 89 6c 24 e8       	mov    %r13,-0x18(%rsp)
  400582:	4c 89 74 24 f0       	mov    %r14,-0x10(%rsp)
  400587:	4c 89 7c 24 f8       	mov    %r15,-0x8(%rsp)
  40058c:	48 83 ec 38          	sub    $0x38,%rsp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:123
  400590:	4c 29 e5             	sub    %r12,%rbp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:107
  400593:	41 89 ff             	mov    %edi,%r15d
  400596:	49 89 f6             	mov    %rsi,%r14
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:123
  400599:	48 c1 fd 03          	sar    $0x3,%rbp
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:107
  40059d:	49 89 d5             	mov    %rdx,%r13
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:124
  4005a0:	31 db                	xor    %ebx,%ebx
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:121
  4005a2:	e8 49 fe ff ff       	callq  4003f0 <_init>
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:124
  4005a7:	48 85 ed             	test   %rbp,%rbp
  4005aa:	74 1a                	je     4005c6 <__libc_csu_init+0x66>
  4005ac:	0f 1f 40 00          	nopl   0x0(%rax)
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:125
  4005b0:	4c 89 ea             	mov    %r13,%rdx
  4005b3:	4c 89 f6             	mov    %r14,%rsi
  4005b6:	44 89 ff             	mov    %r15d,%edi
  4005b9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:124
  4005bd:	48 83 c3 01          	add    $0x1,%rbx
  4005c1:	48 39 eb             	cmp    %rbp,%rbx
  4005c4:	75 ea                	jne    4005b0 <__libc_csu_init+0x50>
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:126
  4005c6:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  4005cb:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  4005d0:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  4005d5:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  4005da:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  4005df:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  4005e4:	48 83 c4 38          	add    $0x38,%rsp
  4005e8:	c3                   	retq   
  4005e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004005f0 <__libc_csu_fini>:
__libc_csu_fini():
/home/abuild/rpmbuild/BUILD/glibc-2.15/csu/elf-init.c:133
  4005f0:	f3 c3                	repz retq 
  4005f2:	90                   	nop
  4005f3:	90                   	nop

Disassembly of section .fini:

00000000004005f4 <_fini>:
_fini():
  4005f4:	55                   	push   %rbp
  4005f5:	48 83 ec 08          	sub    $0x8,%rsp
  4005f9:	e8 06 00 00 00       	callq  400604 <_real_fini>
  4005fe:	48 83 c4 08          	add    $0x8,%rsp
  400602:	5d                   	pop    %rbp
  400603:	c3                   	retq   

0000000000400604 <_real_fini>:
_real_fini():
  400604:	c3                   	retq   
