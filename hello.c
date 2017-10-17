#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("madj");

static int hello_init(void)
{
	pr_debug("Hello, world\n");
	return 0;
}

static void hello_exit(void)
{
	pr_debug("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
