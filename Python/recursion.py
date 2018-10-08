def factorial(base_case):
    ''' Factorial algorithm using recursion'''
    try:
        if int(base_case) <= 1:
            return base_case
        return factorial(int(base_case)-1) * int(base_case)
    except Exception as e:
        return e.args

