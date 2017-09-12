#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8322b8a9, "module_layout" },
	{ 0x206dc9fc, "trace_event_raw_init" },
	{ 0x4f54956d, "ftrace_event_reg" },
	{ 0x17c74c3e, "kthread_stop" },
	{ 0xdc7c5a42, "wake_up_process" },
	{ 0x20900905, "kthread_create_on_node" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0xb363e7e, "current_task" },
	{ 0x1d0bef46, "mutex_unlock" },
	{ 0xaf6227d1, "trace_define_field" },
	{ 0x28318305, "snprintf" },
	{ 0xf6e04730, "event_storage" },
	{ 0xd7be2318, "mutex_lock" },
	{ 0x3d29691a, "event_storage_mutex" },
	{ 0x39e15e5f, "trace_nowake_buffer_unlock_commit" },
	{ 0x84ef15f2, "filter_current_check_discard" },
	{ 0x9621849f, "ring_buffer_event_data" },
	{ 0xfef8a166, "trace_current_buffer_lock_reserve" },
	{ 0x4c4fef19, "kernel_stack" },
	{ 0x78764f4e, "pv_irq_ops" },
	{ 0xe72a7f11, "perf_tp_event" },
	{ 0x7628f3c7, "this_cpu_off" },
	{ 0x9166fada, "strncpy" },
	{ 0xe6602e9f, "perf_trace_buf_prepare" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x1e3a88fb, "trace_seq_printf" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2534686769A13BCA30DF4A2");
