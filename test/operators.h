#ifndef __OPERATORS_H_
#define __OPERATORS_H_

/*!
 * \brief Function object that does nothing.
 */
struct no_op
{
    template <typename T>
    inline void
    operator()(T const&) const
    {
    }
};

/*!
 * \brief Function object that always returns true.
 */
struct true_no_op
{
    template <typename T>
    inline bool
    operator()(T const&) const
    {
        return true;
    }
};

/*!
 * \brief Function object that alternates the return value between true and
 * false, ignoring the argument.
 */
struct alternating_no_op
{
    template <typename T>
    inline bool
    operator()(T const&) const
    {
        return number++ % 2 == 0;
    }

    /*! Needs to be mutable, as the operator() needs to be const. */
    mutable int number;
};

/*!
 * \brief Function object that always returns false.
 */
struct false_no_op
{
    template <typename T>
    inline bool
    operator()(T const&) const
    {
        return false;
    }
};


#endif /* __OPERATORS_H_ */
