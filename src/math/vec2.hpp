#pragma once

#include "pch.hpp"

#include "math.hpp"

namespace math {

template<scalar T>
struct vec2 {
    static const vec2<T> zero;
    static const vec2<T> one;
    static const vec2<T> left;
    static const vec2<T> right;
    static const vec2<T> down;
    static const vec2<T> up;

	T x, y;

	vec2();

	vec2(T all);

	vec2(T x, T y);

	template<scalar U>
	vec2(const vec2<U> &other);

#pragma region Operators

	template<scalar U>
	friend std::ostream &operator<<(std::ostream &lhs, const vec2<U> &rhs);

	T &operator[](size_t index);

	const T &operator[](size_t index) const;

	template<scalar U>
	vec2<bool> operator==(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<bool> operator!=(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<bool> operator<=(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<bool> operator>=(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<bool> operator<(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<bool> operator>(const vec2<U> &rhs) const;

	vec2<bool> operator!() const;

	vec2<T> operator-() const;

	// Vector + Vector

	template<scalar U>
	auto operator+(const vec2<U> &rhs) const;

	template<scalar U>
	auto operator-(const vec2<U> &rhs) const;

	template<scalar U>
	auto operator*(const vec2<U> &rhs) const;

	template<scalar U>
	auto operator/(const vec2<U> &rhs) const;

	template<scalar U>
	vec2<T> &operator+=(const vec2<U> &rhs);

	template<scalar U>
	vec2<T> &operator-=(const vec2<U> &rhs);

	template<scalar U>
	vec2<T> &operator*=(const vec2<U> &rhs);

	template<scalar U>
	vec2<T> &operator/=(const vec2<U> &rhs);

	// Vector + Scalar

	template<scalar U>
	auto operator*(U rhs) const;

	template<scalar U>
	auto operator/(U rhs) const;

	template<scalar U>
	vec2<T> &operator*=(U rhs);

	template<scalar U>
	vec2<T> &operator/=(U rhs);

	// Scalar + Vector

	template<scalar L, scalar R>
	friend auto operator*(L lhs, const vec2<R> &rhs);

#pragma endregion

};

using bvec2 = vec2<bool>;
using ivec2 = vec2<int32_t>;
using uvec2 = vec2<uint32_t>;
using fvec2 = vec2<float>;
using dvec2 = vec2<double>;

template<scalar T>
bool all(const vec2<T> &vec);

template<scalar T>
bool any(const vec2<T> &vec);

template<scalar L, scalar R,
		typename Ret = std::common_type_t<L, R>>
vec2<Ret> cross(const vec2<L> &lhs, const vec2<R> &rhs);

template<scalar A, scalar B,
		typename Ret = std::common_type_t<A, B>>
Ret distance(const vec2<A> &a, const vec2<B> &b);

template<scalar A, scalar B,
		typename Ret = std::common_type_t<A, B>>
Ret dot(const vec2<A> &a, const vec2<B> &b);

template<scalar T, scalar Epsilon = decltype(epsilon)>
bool is_normalized(const vec2<T> &vec, Epsilon epsilon = math::epsilon);

template<scalar T>
T length(const vec2<T> &vec);

template<scalar T>
vec2<T> normalize(const vec2<T> &vec);

template<scalar To, scalar From,
		typename Ret = std::common_type_t<To, From>>
vec2<Ret> proj(const vec2<To> &to, const vec2<From> &from);

#pragma region Component-Wise Math Wrappers

template<scalar X>
vec2<X> fract(const vec2<X> &x);

template<scalar From, scalar To, scalar Weight,
		typename Ret = std::common_type_t<From, To, Weight>>
vec2<Ret> lerp(const vec2<From> &from, const vec2<To> &to, Weight weight);

template<scalar A, scalar B,
		typename Ret = std::common_type_t<A, B>>
vec2<Ret> max(const vec2<A> &a, const vec2<B> &b);

template<scalar A, scalar B, scalar... Others,
		typename Ret = std::common_type_t<A, B, Others...>>
vec2<Ret> max(const vec2<A> &a, const vec2<B> &b,
		const vec2<Others> &...others);

template<scalar A, scalar B,
		typename Ret = std::common_type_t<A, B>>
vec2<Ret> min(const vec2<A> &a, const vec2<B> &b);

template<scalar A, scalar B, scalar... Others,
		typename Ret = std::common_type_t<A, B, Others...>>
vec2<Ret> min(const vec2<A> &a, const vec2<B> &b,
		const vec2<Others> &...others);

template<scalar X, scalar Y,
		typename Ret = std::common_type_t<X, Y>>
vec2<Ret> mod(const vec2<X> &x, const vec2<Y> &y);

#pragma endregion

}

#include "vec2.inl"
