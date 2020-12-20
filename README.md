QVM: Generic C++ library for working with Quaternions, Vectors and Matrices

Official documentation: https://boostorg.github.io/qvm/

* Emphasis on 2, 3 and 4-dimensional operations needed in graphics, video games and simulation applications.
* Free function templates operate on any compatible user-defined Quaternion, Vector or Matrix type.
* Enables Quaternion, Vector and Matrix types from different libraries to be safely mixed in the same expression.
* Type-safe mapping between compatible lvalue types with no temporary objects; f.ex. transpose remaps the access to the elements, rather than transforming the matrix.
* Requires only {CPP}03.
* Zero dependencies.

Please post questions and feedback on the Boost Developers Mailing List or in `#boost` in cpplang.slack.com.

> NOTE:
>
> QVM is distributed as part of Boost (but it does not depend on any other Boost library).
>
> In addition, QVM is available in single-header format for maximum portability. There are two versions of this distribution (the links below point to the actual header files for direct download):
> * [qvm.hpp](https://boostorg.github.io/qvm/qvm.hpp): single header containing all QVM code, including complete swizzling overloads.
> * [qvm_lite.hpp](https://boostorg.github.io/qvm/qvm_lite.hpp): single header containing everything except for the swizzling overloads.

Copyright (c) 2018-2021 Emil Dotchevski. Distributed under the [Boost Software License, Version 1.0](http://www.boost.org/LICENSE_1_0.txt).
