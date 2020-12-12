#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        using boost::enable_if;
        using boost::enable_if_c;
        using boost::lazy_enable_if;
        using boost::lazy_enable_if_c;
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class Q>
        struct
        quat_traits
            {
            typedef void scalar_type;
            };

        namespace
        is_quaternion_detail
            {
            template <class>
            struct
            is_void
                {
                static bool const value=false;
                };

            template <>
            struct
            is_void<void>
                {
                static bool const value=true;
                };
            }

        template <class T>
        struct
        is_quat
            {
            static bool const value=!is_quaternion_detail::is_void<typename quat_traits<T>::scalar_type>::value;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class V>
        struct
        vec_traits
            {
            static int const dim=0;
            typedef void scalar_type;
            };

        template <class T>
        struct
        is_vec
            {
            static bool const value=vec_traits<T>::dim>0;
            };
        }
    }



namespace
boost
    {
    namespace
    qvm
        {
        template <class M>
        struct
        mat_traits
            {
            static int const rows=0;
            static int const cols=0;
            typedef void scalar_type;
            };

        template <class T>
        struct
        is_mat
            {
            static bool const value=mat_traits<T>::rows>0 && mat_traits<T>::cols>0;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        namespace
        deduce_scalar_detail
            {
            template <class A,class B> struct deduce_scalar_impl { };

            template <class T>
            struct
            deduce_scalar_impl<T,T>
                {
                typedef T type;
                };

            template <> struct deduce_scalar_impl<signed char,unsigned char> { typedef unsigned char type; };
            template <> struct deduce_scalar_impl<signed char,unsigned short> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<signed char,unsigned int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<signed char,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed char,signed short> { typedef signed short type; };
            template <> struct deduce_scalar_impl<signed char,signed int> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed char,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<signed char,float> { typedef float type; };
            template <> struct deduce_scalar_impl<signed char,double> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned char,unsigned short> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<unsigned char,unsigned int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned char,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<unsigned char,signed short> { typedef signed short type; };
            template <> struct deduce_scalar_impl<unsigned char,signed int> { typedef signed int type; };
            template <> struct deduce_scalar_impl<unsigned char,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<unsigned char,float> { typedef float type; };
            template <> struct deduce_scalar_impl<unsigned char,double> { typedef double type; };
            template <> struct deduce_scalar_impl<signed short,unsigned short> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<signed short,unsigned int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<signed short,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed short,signed int> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed short,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<signed short,float> { typedef float type; };
            template <> struct deduce_scalar_impl<signed short,double> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned short,unsigned int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned short,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<unsigned short,signed int> { typedef signed int type; };
            template <> struct deduce_scalar_impl<unsigned short,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<unsigned short,float> { typedef float type; };
            template <> struct deduce_scalar_impl<unsigned short,double> { typedef double type; };
            template <> struct deduce_scalar_impl<signed int,unsigned int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<signed int,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed int,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<signed int,float> { typedef float type; };
            template <> struct deduce_scalar_impl<signed int,double> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned int,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<unsigned int,signed long> { typedef signed long type; };
            template <> struct deduce_scalar_impl<unsigned int,float> { typedef float type; };
            template <> struct deduce_scalar_impl<unsigned int,double> { typedef double type; };
            template <> struct deduce_scalar_impl<signed long,unsigned long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed long,float> { typedef float type; };
            template <> struct deduce_scalar_impl<signed long,double> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned long,float> { typedef float type; };
            template <> struct deduce_scalar_impl<unsigned long,double> { typedef double type; };
            template <> struct deduce_scalar_impl<float,double> { typedef double type; };

            template <> struct deduce_scalar_impl<unsigned char,signed char> { typedef unsigned char type; };
            template <> struct deduce_scalar_impl<unsigned short,signed char> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<unsigned int,signed char> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned long,signed char> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed short,signed char> { typedef signed short type; };
            template <> struct deduce_scalar_impl<signed int,signed char> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed long,signed char> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,signed char> { typedef float type; };
            template <> struct deduce_scalar_impl<double,signed char> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned short,unsigned char> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<unsigned int,unsigned char> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned long,unsigned char> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed short,unsigned char> { typedef signed short type; };
            template <> struct deduce_scalar_impl<signed int,unsigned char> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed long,unsigned char> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,unsigned char> { typedef float type; };
            template <> struct deduce_scalar_impl<double,unsigned char> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned short,signed short> { typedef unsigned short type; };
            template <> struct deduce_scalar_impl<unsigned int,signed short> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned long,signed short> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed int,signed short> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed long,signed short> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,signed short> { typedef float type; };
            template <> struct deduce_scalar_impl<double,signed short> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned int,unsigned short> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned long,unsigned short> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed int,unsigned short> { typedef signed int type; };
            template <> struct deduce_scalar_impl<signed long,unsigned short> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,unsigned short> { typedef float type; };
            template <> struct deduce_scalar_impl<double,unsigned short> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned int,signed int> { typedef unsigned int type; };
            template <> struct deduce_scalar_impl<unsigned long,signed int> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed long,signed int> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,signed int> { typedef float type; };
            template <> struct deduce_scalar_impl<double,signed int> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned long,unsigned int> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<signed long,unsigned int> { typedef signed long type; };
            template <> struct deduce_scalar_impl<float,unsigned int> { typedef float type; };
            template <> struct deduce_scalar_impl<double,unsigned int> { typedef double type; };
            template <> struct deduce_scalar_impl<unsigned long,signed long> { typedef unsigned long type; };
            template <> struct deduce_scalar_impl<float,signed long> { typedef float type; };
            template <> struct deduce_scalar_impl<double,signed long> { typedef double type; };
            template <> struct deduce_scalar_impl<float,unsigned long> { typedef float type; };
            template <> struct deduce_scalar_impl<double,unsigned long> { typedef double type; };
            template <> struct deduce_scalar_impl<double,float> { typedef double type; };
            }

        template <class A,class B>
        struct
        deduce_scalar
            {
            typedef typename deduce_scalar_detail::deduce_scalar_impl<A,B>::type type;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class Scalar>
        struct
        scalar_traits
            {
            static
            Scalar
            value( int v )
                {
                return Scalar(v);
                }
            };

        template <class T>
        struct
        is_scalar
            {
            static bool const value=false;
            };
        template <> struct is_scalar<char> { static bool const value=true; };
        template <> struct is_scalar<signed char> { static bool const value=true; };
        template <> struct is_scalar<unsigned char> { static bool const value=true; };
        template <> struct is_scalar<signed short> { static bool const value=true; };
        template <> struct is_scalar<unsigned short> { static bool const value=true; };
        template <> struct is_scalar<signed int> { static bool const value=true; };
        template <> struct is_scalar<unsigned int> { static bool const value=true; };
        template <> struct is_scalar<signed long> { static bool const value=true; };
        template <> struct is_scalar<unsigned long> { static bool const value=true; };
        template <> struct is_scalar<float> { static bool const value=true; };
        template <> struct is_scalar<double> { static bool const value=true; };
        template <> struct is_scalar<long double> { static bool const value=true; };

        namespace
        qvm_detail
            {
            template <class A,bool M=is_mat<A>::value,bool Q=is_quat<A>::value,bool V=is_vec<A>::value,bool S=is_scalar<A>::value>
            struct
            scalar_impl
                {
                };

            template <class A>
            struct
            scalar_impl<A,true,false,false,false>
                {
                typedef typename mat_traits<A>::scalar_type type;
                };

            template <class A>
            struct
            scalar_impl<A,false,true,false,false>
                {
                typedef typename quat_traits<A>::scalar_type type;
                };

            template <class A>
            struct
            scalar_impl<A,false,false,true,false>
                {
                typedef typename vec_traits<A>::scalar_type type;
                };

            template <class S>
            struct
            scalar_impl<S,false,false,false,true>
                {
                typedef S type;
                };
            }

        template <class A>
        struct
        scalar
            {
            typedef typename qvm_detail::scalar_impl<A>::type type;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class T>
        struct quat;

        template <class Q>
        struct
        deduce_quat
            {
            typedef Q type;
            };

        namespace
        qvm_detail
            {
            template <class A,class B,
                bool QA=is_quat<A>::value,
                bool QB=is_quat<B>::value,
                class SA=typename scalar<A>::type,
                class SB=typename scalar<B>::type,
                class SR=typename deduce_scalar<typename scalar<A>::type,typename scalar<B>::type>::type>
            struct
            deduce_q2_default
                {
                typedef quat<SR> type;
                };

            template <class Q,class S>
            struct
            deduce_q2_default<Q,Q,true,true,S,S,S>
                {
                typedef Q type;
                };

            template <class Q,class S,class SV>
            struct
            deduce_q2_default<Q,S,true,false,SV,S,SV>
                {
                typedef Q type;
                };

            template <class S,class Q,class SV>
            struct
            deduce_q2_default<S,Q,false,true,S,SV,SV>
                {
                typedef Q type;
                };
            }

        template <class A,class B>
        struct
        deduce_quat2
            {
            typedef typename qvm_detail::deduce_q2_default<A,B>::type type;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class T>
        struct
        quat
            {
            T a[4];
            template <class R>
            operator R() const
                {
                R r;
                assign(r,*this);
                return r;
                }
            };

        template <class Q>
        struct quat_traits;

        template <class T>
        struct
        quat_traits< quat<T> >
            {
            typedef quat<T> this_quaternion;
            typedef T scalar_type;

            template <int I>
            static
            scalar_type
            read_element( this_quaternion const & x )
                {
                return x.a[I];
                }

            template <int I>
            static
            scalar_type &
            write_element( this_quaternion & x )
                {
                return x.a[I];
                }
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class A,class B>
        typename lazy_enable_if_c<
            is_quat<A>::value && is_scalar<B>::value,
            deduce_quat2<A,B> >::type
        operator*( A const & a, B b )
            {
            typedef typename deduce_quat2<A,B>::type R;
            R r;
            quat_traits<R>::template write_element<0>(r)=quat_traits<A>::template read_element<0>(a)*b;
            quat_traits<R>::template write_element<1>(r)=quat_traits<A>::template read_element<1>(a)*b;
            quat_traits<R>::template write_element<2>(r)=quat_traits<A>::template read_element<2>(a)*b;
            quat_traits<R>::template write_element<3>(r)=quat_traits<A>::template read_element<3>(a)*b;
            return r;
            }
        }
    }


namespace
test_qvm
    {
    template <class Tag,class T=float>
    struct
    quaternion
        {
        T a[4];
        mutable T b[4];

        explicit
        quaternion( T start=T(0), T step=T(0) )
            {
            for( int i=0; i!=4; ++i,start+=step )
                a[i]=b[i]=start;
            }
        };

    template <class Tag1,class T1,class Tag2,class T2>
    void
    dump_ab( quaternion<Tag1,T1> const & a, quaternion<Tag2,T2> const & b )
        {
        detail::dump_ab(a.a,b.a);
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class>
        struct quat_traits;

        template <class QuatType,class ScalarType>
        struct
        quat_traits_defaults
            {
            typedef QuatType quat_type;
            typedef ScalarType scalar_type;

            template <int I>
            static
            scalar_type
            read_element( quat_type const & x )
                {
                return quat_traits<quat_type>::template write_element<I>(const_cast<quat_type &>(x));
                }
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        template <class Tag,class T>
        struct
        quat_traits< test_qvm::quaternion<Tag,T> >:
            quat_traits_defaults<test_qvm::quaternion<Tag,T>,T>
            {
            typedef quat_traits_defaults<test_qvm::quaternion<Tag,T>,T> base;

            template <int I>
            static
            typename base::scalar_type &
            write_element( typename base::quat_type & m )
                {
                return m.a[I];
                }
            };

        template <class Tag,class T>
        struct
        deduce_quat2<test_qvm::quaternion<Tag,T>,test_qvm::quaternion<Tag,T> >
            {
            typedef test_qvm::quaternion<Tag,T> type;
            };
        }
    }


namespace
boost
    {
    namespace
    qvm
        {
        namespace
        sfinae
            {
            using boost::qvm::operator*;
            }
        }
    }


namespace
    {
    struct Q1;
    struct Q2;
    struct Q3;
    }



template <class T,class U> struct same_type_tester;
template <class T> struct same_type_tester<T,T> { };
template <class T,class U> void test_same_type( T, U ) { same_type_tester<T,U>(); }


int main()
{
    using namespace boost::qvm::sfinae;
    test_qvm::quaternion<Q1> const x(42,1);
    test_same_type(x,x*2);
    test_qvm::quaternion<Q1> y=x*2;
    return 0;
}
