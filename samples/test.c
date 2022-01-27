#include "../map/map.h"
#include <openutils/sstring/sstring.h>

size_t hash(void *key);
size_t hash(void *key)
{
    sstring x = new_sstring(1, (const char *)key);
    size_t h = x.hash(&x);
    x.destructor(&x);
    return h;
}

size_t value_hash(void *val);
size_t value_hash(void *val)
{
    union convert_ptr_size_t
    {
        void *ptr;
        size_t num;
    };
    union convert_ptr_size_t x;
    x.ptr = val;
    return x.num;
}

int equal(void *ptr, void *ptr2);
int equal(void *ptr, void *ptr2)
{
    sstring x = new_sstring(1, (const char *)ptr);
    sstring y = new_sstring(1, (const char *)ptr2);
    int eq = x.compare(&x, y.c_str(&y));
    x.destructor(&x);
    y.destructor(&y);
    return eq;
}

int main(int argc, char const **argv)
{
    map_t m = new_map_t(hash, value_hash, equal, sizeof(char *), sizeof(int));
    for (int i = 1; i < argc; i++)
        m.add(&m, (char *)argv[i], (void *)i);
    for (iter_map_t i = m.iterator(&m); i.c_loop(&i); i.next(&i))
        printf("%s: %d\n", i.cget(&i)->key, i.cget(&i)->value);
    printf("Length = %lu\n", m.length(&m));
    printf("Capacity = %lu\n", m.capacity(&m));
    printf("Max Depth = %lu\n", m.max_depth(&m));
    printf("HASH = %lu\n", m.hash(&m));
    printf("Error Rate = %Lf\n", m.error_rate(&m, argc - 1));
    m.destructor(&m);
    return 0;
}