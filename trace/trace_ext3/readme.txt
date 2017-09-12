
case_使用systemtap和kprobe跟踪自己开发的模块.txt

1.sles11sp1:/opt/proc_mtest # ls
Makefile  mtest.stp  proc_mtest.c  proc_mtest.ko.debug  trace_mtest.c

 2.kprobe 正常跟踪， 结论：kprobe可以跟踪模块中的函数。
Jan  1 07:41:34 sles11sp1 kernel: [ 3898.313236] Registered a jprobe.
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475312] mtest_openprocess cat pid=4432
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475352] Pid: 4432, comm: cat Tainted: P          N  2.6.32.59-0.7-default #1
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475355] Call Trace:
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475370]  [<ffffffff810061dc>] dump_trace+0x6c/0x2d0
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475377]  [<ffffffff8139bab6>] dump_stack+0x69/0x73
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475385]  [<ffffffffa009009d>] jmtest_read+0x2d/0x38 [trace_mtest]
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475413]  [<ffffffff81154e87>] proc_reg_read+0x77/0xc0
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475428]  [<ffffffff810ffe77>] vfs_read+0xc7/0x130
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475434]  [<ffffffff810fffe3>] sys_read+0x53/0xa0
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475440]  [<ffffffff81002f7b>] system_call_fastpath+0x16/0x1b
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475454]  [<00007f9c06205f30>] 0x7f9c06205f30
Jan  1 07:42:31 sles11sp1 kernel: [ 3955.475471] mtest_read


sles11sp1:~ # tail -f /var/log/messages
Jan  1 06:37:40 sles11sp1 xinetd[3140]: Reading included configuration file: /etc/xinetd.d/vnc [file=/etc/xinetd.d/vnc] [line=15]
Jan  1 06:37:40 sles11sp1 xinetd[3140]: Reading included configuration file: /etc/xinetd.d/vsftpd [file=/etc/xinetd.d/vsftpd] [line=88]
Jan  1 06:37:40 sles11sp1 xinetd[3140]: xinetd Version 2.3.14 started with libwrap loadavg options compiled in.
Jan  1 06:37:40 sles11sp1 xinetd[3140]: Started working: 5 available services
Jan  1 06:37:45 sles11sp1 kernel: [   69.048028] eth0: no IPv6 routers present
Jan  1 06:52:23 sles11sp1 sshd[3280]: Accepted publickey for root from 192.168.5.20 port 52590 ssh2
Jan  1 07:11:50 sles11sp1 sshd[3322]: Accepted publickey for root from 192.168.5.20 port 52600 ssh2
Jan  1 07:11:50 sles11sp1 sshd[3322]: Received disconnect from 192.168.5.20: 11: disconnected by user
Jan  1 07:12:15 sles11sp1 kernel: [ 2139.211532] Registered a jprobe.
Jan  1 07:12:55 sles11sp1 sshd[3547]: Accepted publickey for root from 192.168.5.20 port 52602 ssh2


Jan  1 07:14:01 sles11sp1 kernel: [ 2245.751205] process rm pid=3583 inode=ffff8800394cc400
Jan  1 07:14:43 sles11sp1 kernel: [ 2287.746783] process rm pid=3587 inode=ffff8800394c3400

sles11sp1:/opt/proc_mtest # ls
Makefile  mtest.stp  proc_mtest.c  proc_mtest.ko.debug  trace_mtest.c


sles11sp1:/opt/proc_mtest # stap mtest.stp 
semantic error: missing x86_64 kernel/module debuginfo under '/lib/modules/2.6.32.59-0.7-default/build' while resolving probe point module("proc_mtest").function("mtest_read")
Pass 2: analysis failed.  Try again with another '--vp 01' option.


strace 一下
sles11sp1:/opt/proc_mtest # strace -o a  stap mtest.stp
semantic error: missing x86_64 kernel/module debuginfo under '/lib/modules/2.6.32.59-0.7-default/build' while resolving probe point module("proc_mtest").function("mtest_read")
Pass 2: analysis failed.  Try again with another '--vp 01' option.

发现去找/lib/modules/2.6.32.59-0.7-default/kernel 下面的各个ko,于是乎 


sles11sp1:/opt/proc_mtest # cp proc_mtest.ko  /lib/modules/2.6.32.59-0.7-default/kernel/drivers/
sles11sp1:/opt/proc_mtest # strace -o b  stap mtest.stp
^Csles11sp1:/opt/proc_mtest # stap mtest.stp
mtest read by traced


OK，解决。


