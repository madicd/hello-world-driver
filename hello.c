#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("madj");

static u64 jiffies_before;

static int __init hello_init(void)
{
	jiffies_before = get_jiffies_64();
	pr_debug("Hello, world\n");
	return 0;
}

static void __exit hello_exit(void)
{
	u64 jiffies_after;
	unsigned long diff;

	jiffies_after = get_jiffies_64();
	diff = jiffies_to_msecs(jiffies_after-jiffies_before);
	pr_debug("Goodbye, cruel world: %lu\n", diff/1000);
}

module_init(hello_init);
module_exit(hello_exit);
