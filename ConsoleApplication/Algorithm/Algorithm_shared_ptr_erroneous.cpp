#include <iostream>
#include <boost/shared_ptr.hpp>

template<class T> struct shared_ptr_traits
{
    typedef T& reference;
};

template<> struct shared_ptr_traits<void>
{
    typedef void reference;
};

static int  counter[10] = { 0, };

template<class T> class shared_ptr
{
public:
    typedef shared_ptr<T>   this_type;
    typedef T               value_type;
    typedef T*              pointer;
    typedef typename shared_ptr_traits<T>::reference reference;

public:
    shared_ptr(T * p = 0) : px(p), pn(0)
    {
        if( px != NULL )
            pn = new int(1);
    }

    shared_ptr( const shared_ptr& right_ ) : px( 0 ), pn( 0 )
    {
        release();
        px = right_.px;
        pn = right_.pn;
        if( px != NULL )
            *pn += 1;
    }

    ~shared_ptr()
    {
        release();
    }

    shared_ptr& operator=( const shared_ptr& right_ )
    {
        //release();
        //px = right_.px;
        //pn = right_.pn;
        //if( px != NULL )
        //    *pn += 1;
        this_type(right_).swap(*this);
        return *this;
    }

    //operator pointer() const
    //{
    //    return px;
    //}

    void release()
    {
        if( px != NULL && *pn >= 1 )
        {
            *pn -= 1;
            if( *pn == 0 )
            {
                delete px;
                px = NULL;
                delete pn;
                pn = NULL;
            }//if
        }//if
        px = NULL;
        pn = NULL;
    }

    void reset()
    {
        //release();
        this_type().swap(*this);
    }

    void reset(T * p)
    {
        //release();
        //px = p;
        //pn = NULL;
        //if( px != NULL )
        //    pn = new int(1);
        this_type(p).swap(*this);
    }

    int use_count() const { return *pn; }

    reference operator*() const  // never throws
    {
        return *px;
    }

    T* operator->() const  // never throws
    {
        return px;
    }

    void swap( shared_ptr<T>& right_ )
    {
        std::swap( px, right_.px );
        std::swap( pn, right_.pn );
    }

    void unspecified_bool() const
    {
    }

    typedef void (shared_ptr::*unspecified_bool_type)() const;

    operator unspecified_bool_type() const // never throws
    {
        return px == 0 ? 0 : &shared_ptr::unspecified_bool;
    }

private:
    T*      px;
    int*    pn;
};//template<class T> class shared_ptr

void Test( shared_ptr<int> spInt_ )
{
}

int main()
{
    typedef shared_ptr<int>     IntPtr;
    IntPtr spInt = new int(3);

    if( spInt != NULL )
    {
        std::cout << *spInt << std::endl;
    }//if

    IntPtr spInt2 = spInt;
    IntPtr spInt3 = spInt;

    spInt.reset( new int(4) );
    *spInt = 5;
    if( spInt2 != NULL )
    {
        std::cout << *spInt << std::endl;
    }//if
    //int* p = spInt;

    //if( spInt < spInt )
    //{
    //}

    int iData = 5;
    Test( &iData );

    return 0;
    /** output:
    3
    5
    계속하려면 아무 키나 누르십시오 . . .
    */
}//int main()
