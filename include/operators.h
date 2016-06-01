//
// Operators useful for some specific unit tests.
//

#ifndef __OPERATORS_H_
#define __OPERATORS_H_

/*!
 * \brief Generic n-ary function object that does nothing.
 */
struct no_op
{
    template <typename... Args>
    inline void
    operator()(Args...) const
    {
    }
};

/*!
 * \brief Generic n-ary function object that always returns true.
 */
struct true_no_op
{
    template <typename... Args>
    inline bool
    operator()(Args...) const
    {
        return true;
    }
};

/*!
 * \brief Function object that always returns false.
 */
struct false_no_op
{
    template <typename... Args>
    inline bool
    operator()(Args...) const
    {
        return false;
    }
};

/*!
 * \brief Function object that alternates the return value between true and
 * false, ignoring the argument.
 */
struct alternating_no_op
{
    template <typename... Args>
    inline bool
    operator()(Args...) const
    {
        return number++ % 2 == 0;
    }

    /*! Needs to be mutable, as the operator() needs to be const. */
    mutable int number;
};

#endif /* __OPERATORS_H_ */
