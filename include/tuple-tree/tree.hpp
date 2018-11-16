#include <tuple>
#include <map>
#include <utility>

namespace ttree {

template <typename T, typename ...U> class Ttree {
    public:
    using TupleType = std::tuple<T, U...>;
    using Element = T;
    using SubTuple = std::tuple<U...>;
    using SubTree = Ttree<U...>;

    public:
    Ttree() = default;
    
    constexpr std::size_t getHeight() const noexcept {
        return std::tuple_size<TupleType>::value;
    }

    private:
    constexpr static std::size_t tuple_size = std::tuple_size<TupleType>::value;
    static_assert(tuple_size >= 2, "Cannot instantiate a Ttree with a single element");

    std::map<Element, SubTree> _payload;
};

template <typename T1, typename T2> class Ttree<T1, T2> {
    public:
    using TupleType = std::tuple<T1, T2>;
    using Element = T1;
    using SubTuple = T2;
    using SubTree = T2;

    public:
    Ttree() = default;
    
    constexpr std::size_t getHeight() const noexcept {
        return std::tuple_size<TupleType>::value;
    }

    private:
    constexpr static std::size_t tuple_size = std::tuple_size<TupleType>::value;
    std::map<Element, SubTree> _payload;
};

} // namespace ttree
