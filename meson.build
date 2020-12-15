# Copyright (c) 2018-2021 Emil Dotchevski and Reverge Studios, Inc.

# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

project('QVM', 'cpp', default_options : ['cpp_std=c++03', 'b_pch=false'], license : 'boost')

option_qvm_hpp = get_option('qvm_hpp')
option_enable_unit_tests = get_option('qvm_enable_unit_tests')

dep_boost = declare_dependency(include_directories: '../..')
includes = [ include_directories('include') ]
qvm = declare_dependency( include_directories: includes )

if option_enable_unit_tests

	tests = [
		'assign_test',
		'cmp_mm_test',
		'cmp_qq_test',
		'cmp_vv_test',
		'col_mat_test',
		'col_test',
		'conjugate_test',
		'convert_to_test',
		'cross_test',
		'deduce_mat_test',
		'deduce_quat_test',
		'deduce_scalar_test',
		'deduce_vec_test',
		'del_col_test',
		'del_row_col_test',
		'del_row_test',
		'determinant_test',
		'diag_mat_test',
		'diag_test',
		'div_eq_ms_test',
		'div_eq_qs_test',
		'div_eq_vs_test',
		'div_ms_test',
		'div_qs_test',
		'div_vs_test',
		'dot_qq_test',
		'dot_vv_test',
		'eq_mm_test',
		'eq_qq_test',
		'eq_vv_test',
		'identity_mat_test',
		'identity_quat_test',
		'interop_test',
		'inverse_m_test',
		'inverse_q_test',
		'mag_q_test',
		'mag_sqr_q_test',
		'mag_sqr_v_test',
		'mag_v_test',
		'mat_index_test',
		'mat_traits_array_test',
		'math_test',
		'minus_eq_mm_test',
		'minus_eq_qq_test',
		'minus_eq_vv_test',
		'minus_m_test',
		'minus_mm_test',
		'minus_q_test',
		'minus_qq_test',
		'minus_v_test',
		'minus_vv_test',
		'mul_eq_mm_test',
		'mul_eq_ms_test',
		'mul_eq_qq_test',
		'mul_eq_qs_test',
		'mul_eq_vs_test',
		'mul_mm_test',
		'mul_ms_test',
		'mul_mv_test',
		'mul_qq_test',
		'mul_qs_test',
		'mul_qv_test',
		'mul_sm_test',
		'mul_sv_test',
		'mul_vm_test',
		'mul_vs_test',
		'neg_col_test',
		'neg_row_test',
		'normalize_q_test',
		'normalize_v_test',
		'plus_eq_mm_test',
		'plus_eq_qq_test',
		'plus_eq_vv_test',
		'plus_mm_test',
		'plus_qq_test',
		'plus_vv_test',
		'projection_test',
		'quat_traits_array_test',
		'rot_mat_test',
		'rot_quat_test',
		'rotx_mat_test',
		'rotx_quat_test',
		'roty_mat_test',
		'roty_quat_test',
		'rotz_mat_test',
		'rotz_quat_test',
		'row_mat_test',
		'row_test',
		'scalar_cast_m_test',
		'scalar_cast_q_test',
		'scalar_cast_v_test',
		'scalar_traits_test',
		'slerp_test',
		'swap_cols_test',
		'swap_rows_test',
		'swizzle2_test',
		'swizzle2_test2',
		'swizzle2_test3',
		'swizzle2_test4',
		'swizzle3_test',
		'swizzle3_test2',
		'swizzle3_test3',
		'swizzle3_test4',
		'swizzle4_test',
		'swizzle4_test2',
		'swizzle4_test3',
		'swizzle4_test4',
		'to_string_test',
		'transform_test',
		'translation_mat_test',
		'translation_test',
		'transpose_test',
		'vec_index_test',
		'vec_register_test',
		'vec_traits_array_test',
		'zero_mat_test',
		'zero_quat_test',
		'zero_vec_test',
	]

	dep_test_single_header = []
	if option_qvm_hpp
		dep_test_single_header = declare_dependency(compile_args: ['-DBOOST_QVM_TEST_SINGLE_HEADER'])
	endif

	foreach t : tests
		test(t, executable(t, 'test/'+t+'.cpp', dependencies: [qvm, dep_boost, dep_test_single_header]) )
	endforeach

endif
