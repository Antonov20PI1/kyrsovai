#include <UnitTest++/UnitTest++.h>
#include <Base64.h>
#include <Base64.cpp>

SUITE(encodeTest)
{
	TEST(NormalString) {
		CHECK_EQUAL("QUJDZA==", Base64().encode("ABCd"));
	}
	TEST(StringNumbers) {
		CHECK_EQUAL("QUJDZA==", Base64().encode("ABCd"));
	}
	TEST(StringSumbols) {
		CHECK_EQUAL("QUJDZA==", Base64().encode("ABCd"));
	}
	TEST(EmptyString) {
		CHECK_THROW(Base64().encode(""), code_error);
	}
	TEST(RussianSymbols) {
		CHECK_THROW(Base64().encode("ABCд"), code_error);
	}
}

SUITE(decodeTest)
{
	TEST(NormalString) {
		CHECK_EQUAL("ABCd+554!!", Base64().decode("QUJDZCs1NTQhIQ=="));
	}
	TEST(UnacceptableSymbols) {
		CHECK_THROW(Base64().decode("*|-"), code_error);
	}
	TEST(ExtraCharacterEqual) {
		CHECK_THROW(Base64().decode("QUJDRA==="), code_error);
	}
	TEST(EmptyString) {
		CHECK_THROW(Base64().decode(""), code_error);
	}
	TEST(RussianSymbols) {
		CHECK_THROW(Base64().decode("QUффJDRA=="), code_error);
	}
	TEST(EqualInMiddle) {
		CHECK_THROW(Base64().decode("QU=JDRA="), code_error);
	}
}

int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}
