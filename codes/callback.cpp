#include <stdio.h>

struct UserData
{
	int a;
	int b;
};

void println(int a, void *userdata)
{
	printf("callback %d\n", a);
	UserData *data = (UserData *)userdata;
	printf("a=%d, b=%d\n", data->a, data->b);
}

void nope(int x, void (*callback)(int, void *), void *userdata)
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			;
	callback(x, userdata);
}

int main()
{
	UserData data{1, 2};
	nope(5, println, &data);
}