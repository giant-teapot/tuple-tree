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
    Ttree()                   = default;
    Ttree(const Ttree& other) = default;
    Ttree(Ttree&& other)      = default;
    
    constexpr std::size_t getHeight() const noexcept {
        return std::tuple_size<TupleType>::value;
    }

    void push(T elem, U... rest) noexcept {
        const auto& itSubtree =  _payload.find(elem);
        if(itSubtree != std::end(_payload)) {
            itSubtree->second.push(rest...);
        }
        else {
            auto newSubtree = _payload.emplace(std::make_pair(std::move(elem), SubTree{}));
            newSubtree.first->second.push(rest...);
        }
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

    void push(T1 elem, T2 value) noexcept {
        _payload.emplace(std::make_pair(std::move(elem), std::move(value)));
    }

    private:
    constexpr static std::size_t tuple_size = std::tuple_size<TupleType>::value;
    std::map<Element, SubTree> _payload;
};

} // namespace ttree
