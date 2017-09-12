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
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0xfd37820, "struct_module" },
	{ 0xaa136450, "param_get_charp" },
	{ 0x2cd7da6c, "param_set_charp" },
	{ 0x89b301d4, "param_get_int" },
	{ 0x98bd6f46, "param_set_int" },
	{ 0x1b9aca3f, "jprobe_return" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x7f983f2f, "register_jprobe" },
	{ 0xe007de41, "kallsyms_lookup_name" },
	{ 0xea147363, "printk" },
	{ 0xe8928b53, "unregister_jprobe" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "A9C3A200D5077706DCCA62D");
