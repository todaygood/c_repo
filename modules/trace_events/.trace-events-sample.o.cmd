cmd_/opt/trace_events/trace-events-sample.o := gcc -Wp,-MD,/opt/trace_events/.trace-events-sample.o.d  -nostdinc -isystem /usr/lib64/gcc/x86_64-suse-linux/4.7/include -I/usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include -Iarch/x86/include/generated  -I/usr/src/linux-3.7.10-72.g8ec70cd/include -Iinclude -I/usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I/usr/src/linux-3.7.10-72.g8ec70cd/include/uapi -Iinclude/generated/uapi -include /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kconfig.h   -I/opt/trace_events -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -m64 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_AVX=1 -pipe -Wno-sign-compare -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fasynchronous-unwind-tables -g -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO   -I/opt/trace_events  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(trace_events_sample)"  -D"KBUILD_MODNAME=KBUILD_STR(trace_events_sample)" -c -o /opt/trace_events/.tmp_trace-events-sample.o /opt/trace_events/trace-events-sample.c

source_/opt/trace_events/trace-events-sample.o := /opt/trace_events/trace-events-sample.c

deps_/opt/trace_events/trace-events-sample.o := \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/module.h \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/int-ll64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/int-ll64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/bitsperlong.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitsperlong.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/bitsperlong.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/posix_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/stddef.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/stddef.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/compiler-gcc4.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/posix_types_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/posix_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/const.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/stat.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/stat.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/stat.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/enterprise/support.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/symbol/prefix.h) \
  /usr/lib64/gcc/x86_64-suse-linux/4.7/include/stdarg.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/linkage.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/alignment/16.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/stringify.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/bitops.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/paravirt.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/asm.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/xen.h) \
    $(wildcard include/config/x86/invlpg.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitops/sched.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/arch_hweight.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitops/const_hweight.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitops/le.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/byteorder.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/byteorder/little_endian.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/byteorder/little_endian.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/swab.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/swab.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/swab.h \
    $(wildcard include/config/x86/bswap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/byteorder/generic.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/typecheck.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/kmsg/ids.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
    $(wildcard include/config/hotplug.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kern_levels.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/dynamic_debug.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/kernel.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/sysinfo.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
    $(wildcard include/config/x86/internode/cache/shift.h) \
    $(wildcard include/config/x86/vsmp.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/seqlock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/bug.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/x86/xen.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
    $(wildcard include/config/ia32/emulation.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/page.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/page_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/physical/align.h) \
    $(wildcard include/config/flatmem.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/page_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/getorder.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/processor.h \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/m386.h) \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/vm86.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/vm86.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ptrace.h \
    $(wildcard include/config/x86/64/xen.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ptrace-abi.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/segment.h \
    $(wildcard include/config/x86/32/lazy/gs.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/paravirt/debug.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/desc_defs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/kmap_types.h \
    $(wildcard include/config/debug/highmem.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/kmap_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/compat/vdso.h) \
    $(wildcard include/config/proc/fs.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/pgtable_64_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/ptrace.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/math_emu.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/sigcontext.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/current.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/percpu.h \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/msr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/msr-index.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/ioctl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ioctl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/ioctl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/ioctl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/errno.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/errno.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/errno-base.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cpumask.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/bitmap.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/string.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/string.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/string_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/paravirt.h \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/paravirt/spinlocks.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/special_insns.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/personality.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/personality.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/math64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/div64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/div64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/err.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/irqflags.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ftrace.h \
    $(wildcard include/config/function/tracer.h) \
    $(wildcard include/config/dynamic/ftrace.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/atomic.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cmpxchg.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cmpxchg_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/atomic64_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/atomic-long.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/bottom_half.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/barrier.h \
    $(wildcard include/config/x86/ppro/fence.h) \
    $(wildcard include/config/x86/oostore.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/spinlock_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/spinlock_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/rwlock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rwlock_types.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/spinlock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rwlock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/time.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/uidgid.h \
    $(wildcard include/config/uidgid/strict/type/checks.h) \
    $(wildcard include/config/user/ns.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/highuid.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kmod.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/cma.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/wait.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/wait.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/nodemask.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/notifier.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/errno.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/errno.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/rwsem.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/srcu.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/user/qs.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/preempt/rt.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/completion.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rcutree.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/jiffies.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/timex.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/timex.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/param.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/param.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/param.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/timex.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/mmzone.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/mmzone_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/smp.h \
    $(wildcard include/config/x86/io/apic.h) \
    $(wildcard include/config/x86/32/smp.h) \
    $(wildcard include/config/debug/nmi/selftest.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/x86/numaq.h) \
    $(wildcard include/config/eisa.h) \
    $(wildcard include/config/x86/mpparse.h) \
    $(wildcard include/config/acpi.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/mpspec_def.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/x86_init.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/bootparam.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/screen_info.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/screen_info.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/apm_bios.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/apm_bios.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/edd.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/edd.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/e820.h \
    $(wildcard include/config/efi.h) \
    $(wildcard include/config/intel/txt.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/memtest.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ioport.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ist.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/video/edid.h \
    $(wildcard include/config/x86.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/apicdef.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/apic.h \
    $(wildcard include/config/x86/x2apic.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pm.h \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/provide/ohci1394/dma/init.h) \
    $(wildcard include/config/x86/visws/apic.h) \
    $(wildcard include/config/x86/f00f/bug.h) \
    $(wildcard include/config/x86/cyclone/timer.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/x86/intel/mid.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/acpi.h \
    $(wildcard include/config/xen/privileged/guest.h) \
    $(wildcard include/config/acpi/pv/sleep.h) \
    $(wildcard include/config/processor/external/control.h) \
    $(wildcard include/config/acpi/numa.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/acpi/pdc_intel.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/numa.h \
    $(wildcard include/config/numa/emu.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/topology.h \
    $(wildcard include/config/x86/ht.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/topology.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/numa_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/mmu.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/realmode.h \
    $(wildcard include/config/acpi/sleep.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/io.h \
    $(wildcard include/config/paravirt/xen.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/generic/iomap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/vmalloc.h \
    $(wildcard include/config/mmu.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/vsyscall.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/vvar.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/io_apic.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/irq_vectors.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/sparsemem.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pfn.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rbtree.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/sysctl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/elf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/elf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/user.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/user_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/auxvec.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/vdso.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/elf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/elf-em.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kobject.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/sysfs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kobject_ns.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kref.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/tracepoint.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/static_key.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/jump_label.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/export.h \
    $(wildcard include/config/modversions.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/module.h \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/mcore2.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/melan.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mviac7.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kthread.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/cfs/bandwidth.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/generic/kernel/thread.h) \
    $(wildcard include/config/mm/owner.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/sched.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/capability.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/capability.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/auxvec.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/auxvec.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/guard.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/uprobes.h \
    $(wildcard include/config/arch/supports/uprobes.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/uprobes.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/cputime.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/cputime.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/sem.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/sem.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ipc.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/ipc.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ipcbuf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/ipcbuf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/sembuf.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/signal.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/signal.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/signal.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/signal-defs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/siginfo.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/siginfo.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/siginfo.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pid.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/proportions.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/percpu_counter.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/seccomp/filter.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/seccomp.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/seccomp.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/seccomp_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/unistd.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/unistd.h \
    $(wildcard include/config/x86/x32/abi.h) \
  arch/x86/include/generated/uapi/asm/unistd_64.h \
  arch/x86/include/generated/asm/unistd_64_x32.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/ia32_unistd.h \
  arch/x86/include/generated/asm/unistd_32_ia32.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rculist.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/resource.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/resource.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/resource.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/resource.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/resource.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/timerqueue.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/latencytop.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/key.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/aio.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/aio_abi.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/uio.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/uio.h \
  /opt/trace_events/trace-events-sample.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/trace/define_trace.h \
  /opt/trace_events/./trace-events-sample.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/trace/ftrace.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ftrace_event.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ring_buffer.h \
    $(wildcard include/config/ring/buffer/allow/swap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kmemcheck.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/mm.h \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/kernel/desktop.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/range.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/bit_spinlock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/shrinker.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/pgtable.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/pgtable_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/pgtable.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/s390.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/huge_mm.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/vm_event_item.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/seq_file.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/trace_seq.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kdev_t.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/kdev_t.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/dcache.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/rculist_bl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/list_bl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/path.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/radix-tree.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/semaphore.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/fiemap.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/migrate_mode.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/percpu-rwsem.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/delay.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/delay.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/delay.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/blk_types.h \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/fs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/limits.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/dqblk_xfs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/dqblk_v1.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/dqblk_v2.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/dqblk_qtree.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/projid.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/quota.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/nfs_fs_i.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/fcntl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/fcntl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/fcntl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/asm-generic/fcntl.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/hardirq.h \
    $(wildcard include/config/generic/hardirqs.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/x86/thermal/vector.h) \
    $(wildcard include/config/x86/mce/threshold.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irq.h \
    $(wildcard include/config/generic/pending/irq.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irqreturn.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irqnr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/irqnr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/irq.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/irq_regs.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
    $(wildcard include/config/sparse/irq.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/hw_irq.h \
    $(wildcard include/config/irq/remap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/profile.h \
    $(wildcard include/config/profiling.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/sections.h \
    $(wildcard include/config/debug/rodata.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/sections.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/x86/wp/works/ok.h) \
    $(wildcard include/config/x86/intel/usercopy.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/smap.h \
    $(wildcard include/config/x86/smap.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/uaccess_64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/perf_event.h \
    $(wildcard include/config/cgroup/perf.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/perf_event.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cgroup.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/cgroupstats.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/taskstats.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/prio_heap.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/idr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/xattr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/slab.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/slab_def.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kmalloc_sizes.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/xattr.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cgroup_subsys.h \
    $(wildcard include/config/cgroup/debug.h) \
    $(wildcard include/config/cgroup/cpuacct.h) \
    $(wildcard include/config/cgroup/device.h) \
    $(wildcard include/config/cgroup/freezer.h) \
    $(wildcard include/config/net/cls/cgroup.h) \
    $(wildcard include/config/netprio/cgroup.h) \
    $(wildcard include/config/cgroup/hugetlb.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/perf_event.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/stacktrace.h \
    $(wildcard include/config/frame/pointer.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/uaccess.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ptrace.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/uapi/linux/ptrace.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/local64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/asm-generic/local64.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/local.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/hw_breakpoint.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kdebug.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/kdebug.h \
    $(wildcard include/config/kexec.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pid_namespace.h \
    $(wildcard include/config/pid/ns.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/nsproxy.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ftrace.h \
    $(wildcard include/config/have/function/trace/mcount/test.h) \
    $(wildcard include/config/stack/tracer.h) \
    $(wildcard include/config/ftrace/syscalls.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/trace_clock.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/kallsyms.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/cpu.h \
    $(wildcard include/config/arch/has/cpu/autoprobe.h) \
    $(wildcard include/config/arch/cpu/probe/release.h) \
    $(wildcard include/config/pm/sleep/smp.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/node.h \
    $(wildcard include/config/memory/hotplug/sparse.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/klist.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/ratelimit.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/device.h \
    $(wildcard include/config/x86/dev/dma/ops.h) \
    $(wildcard include/config/intel/iommu.h) \
    $(wildcard include/config/amd/iommu.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/pm_wakeup.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/irq_work.h \
  /usr/src/linux-3.7.10-72.g8ec70cd/include/linux/perf_regs.h \
    $(wildcard include/config/have/perf/regs.h) \
  /usr/src/linux-3.7.10-72.g8ec70cd/arch/x86/include/asm/perf_regs.h \

/opt/trace_events/trace-events-sample.o: $(deps_/opt/trace_events/trace-events-sample.o)

$(deps_/opt/trace_events/trace-events-sample.o):
