#include <libUnit/unit.h>
#include "macroman.h"
#include "utf8.h"

#if defined(UNIT_TEST)

/* EV Nova uses some more complex type names in the resource fork, which is
 * a use case that will need to be handled. An example of such a type name is
 * sÿst. */
TEST_CASE(NovaResourceType_syst, ConvertToUTF8)
{
	char macroman_string[4] = { 0x73, 0xD8, 0x73, 0x74 };
	char *utf8 = u8"sÿst";

	const char *result = utf8_from_macroman(macroman_string, 4);
	int err = strcmp(result, utf8);

	ASSERT_EQ(err, 0);
}

TEST_CASE(NovaResourceType_syst, ConvertFromUTF8)
{
	char macroman_string[4] = { 0x73, 0xD8, 0x73, 0x74 };
	char *utf8 = u8"sÿst";

	size_t len = 0;
	const char *result = macroman_from_utf8(utf8, &len);
//	int err = strncmp(result, macroman_string, 4);

//	ASSERT_EQ(err, 0);
//	ASSERT_EQ(len, 4);
}


int main(int argc, const char **argv)
{
	return start_tests();
}

#endif
