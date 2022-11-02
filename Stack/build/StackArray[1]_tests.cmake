add_test( StackArrayTest.FunctionTests /home/julio-1610/Workspace/TO/Stack/Stack/build/StackArray [==[--gtest_filter=StackArrayTest.FunctionTests]==] --gtest_also_run_disabled_tests)
set_tests_properties( StackArrayTest.FunctionTests PROPERTIES WORKING_DIRECTORY /home/julio-1610/Workspace/TO/Stack/Stack/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( StackArray_TESTS StackArrayTest.FunctionTests)
