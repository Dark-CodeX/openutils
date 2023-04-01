#include "../sstring/sstring.h"

int main(void)
{
	sstring msg = new_sstring("");
	sstring key = new_sstring("");
	printf("MESSAGE:\n");
	msg.in(&msg);
	printf("KEY:\n");
	key.in(&key);
	printf("ENCRYPTED MESSAGE:\n");
	if (msg.encrypt(&msg, key.c_str(&key)) == false)
	{
		printf("ERR: could not encrypt the message.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	msg.print(&msg, true, "");
	printf("DECRYPTED MESSAGE:\n");
	if (msg.decrypt(&msg, key.c_str(&key)) == false)
	{
		printf("ERR: could not decrypt the message.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	msg.print(&msg, true, "");
	msg.destructor(&msg);
	key.destructor(&key);
	return 0;
}