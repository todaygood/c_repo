cmd_/Code/repository/modules/panic_gen/panic_gen.ko := ld -r -m elf_x86_64 -T /usr/src/linux-3.7.10-1.1/scripts/module-common.lds --build-id  -o /Code/repository/modules/panic_gen/panic_gen.ko /Code/repository/modules/panic_gen/panic_gen.o /Code/repository/modules/panic_gen/panic_gen.mod.o