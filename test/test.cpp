#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <tuple-tree/tree.hpp>

#include <type_traits>


TEST_CASE( "Tuple tree dimension", "[ttree-properties]") {
    //const ttree::Ttree<int> t1; // Forbidden!
    const ttree::Ttree<int, int> t2;
    const ttree::Ttree<int, int, int> t3;
    const ttree::Ttree<int, int, int, int> t4;

    REQUIRE(t2.getHeight() == 2);
    REQUIRE(t3.getHeight() == 3);
    REQUIRE(t4.getHeight() == 4);
}

TEST_CASE( "Element type", "[ttree-properties]") {
    using T1 = ttree::Ttree<int, char>;
    using T2 = ttree::Ttree<char, int, double>;

    REQUIRE(std::is_same<T1::Element, int>::value);
    REQUIRE(std::is_same<T2::Element, char>::value);
}

TEST_CASE( "Sub tuple type", "[ttree-properties]") {
    using T1 = ttree::Ttree<int, char>;
    using T2 = ttree::Ttree<char, int, double>;

    REQUIRE(std::is_same<T1::SubTuple, char>::value);
    REQUIRE(std::is_same<T2::SubTuple, std::tuple<int, double>>::value);
}