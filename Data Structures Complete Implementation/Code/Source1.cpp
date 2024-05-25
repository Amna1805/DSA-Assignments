#include<fstream>
#include<ctime>
#include<ratio>
#include<chrono>
#include<algorithm>
#include<array>
#include<random>
#include"LinkedList(Unsorted).h"
#include"LinkedList(Sorted).h"
#include<list>
#include"BST(Iterative).h"
#include<map>
#include"HashTables(Chaining)div.h"
#include"HashTables(Chaining)mul.h"
#include"HashTables_open_linear.h"
#include"HashTables_open_quad.h"
#include"HashTables_open_doublehash.h"
#include<unordered_map>
template<typename T>
bool find_in_stl_list(list<T>& l, const T& val)
{
    typename list<T>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        if (*it == val)
        {
            return true;
        }
    }
    return false;
}
template<class RandomAccessIterator, class URNG>
void shuffle_r(RandomAccessIterator first, RandomAccessIterator last, URNG&& g)
{
    for (auto i = (last - first) - 1; i > 0; --i)
    {
        uniform_int_distribution<decltype(i)>d(0, i);
        swap(first[i], first[d(g)]);
    }
}
int main()
{
    int i;
    int s = 50;
    int ss = 10;
    int hash_chaining = s / 5;
    int hash_open = s * 1.3;
    int times;
    ofstream f;
    float av1, av2, av3, av4, av5, av6, av7, av8, av9, av10, av11, av12, av13, av14, av15, av16, av17, av18, av19, av20, av21, av22, av23, av24, av25, av26, av27, av28, av29, av30;
    float av31, av32, av33, av34, av35, av36, av37, av38, av39, av40, av41, av42, av43, av44;
    float sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,sum11,sum12,sum13,sum14,sum15,sum16,sum17,sum18,sum19,sum20,sum21,sum22,sum23,sum24,sum25,sum26,sum27,sum28,sum29,sum30;
    sum1 = sum2 = sum3 = sum4 = sum5 = sum6 = sum7 = sum8 = sum9 = sum10 = sum11 = sum12 = sum13 = sum14 = sum15 = sum16 = sum17 = sum18 = sum19 = sum20 = sum21 = sum22 = sum23 = sum24 = sum25 = sum26 = sum27 = sum28 = sum29 = sum30 = 0;
    float sum31,sum32,sum33,sum34,sum35,sum36,sum37,sum38,sum39,sum40,sum41,sum42,sum43,sum44;
    sum31 = sum32 = sum33 = sum34 = sum35 = sum36 = sum37 = sum38 = sum39 = sum40 = sum41 = sum42 = sum43 = sum44 = 0;
    f.open("Records.csv");
    if (f.is_open())
    {
        f << "Records of execution time." << endl;
    }
    else
    {
        cout << "File not opened." << endl;
    }
    for (times = 1; times <= 10; times++)
    {
        dlist_unsorted<int>l;
        dlist<int>ll;
        list<int>lll;
        BST<int>b;
        map<int, int>m;
        pair<int, int>p;
        hashtables_chaining_div<int>h(hash_chaining);
        hashtables_chaining_mul<int>hh(hash_chaining);
        hashtables_open_linear<int>hhh(hash_open);
        hashtables_open_quad<int>hhhh(hash_open);
        hashtables_open_doublehash<int>hhhhh(hash_open);
        unordered_map<int, int>mm;
        pair<int, int>pp;
        f <<"Observation#:" <<times<< endl;
        f << ",INSERT,SEARCH(exsist in array),SEARCH(does not exist in array),DELETE" << endl;
        srand((unsigned)time(NULL));
        array<int, 50000> values;
        for (i = 0; i < s; i++)
        {
            values[i] = 10 + (rand() % 500000);
        }
        array<int, 1000> vals;
        for (i = 0; i < 1000; i++)
        {
            vals[i] = 600000 + (rand() % 2000000000);
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle_r(values.begin(), values.end(), default_random_engine(seed));
        f << "LinkedList(Unsorted),";
                                       //linkedlist(unsorted)
        //Insert
        using namespace std::chrono;
        steady_clock::time_point t1 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            l.push_front(values[i]);
        }
        steady_clock::time_point t2 = steady_clock::now();
        duration<double>time_span1 = duration_cast<duration<double>>(t2 - t1);
        f << time_span1.count() << ",";
        sum1 = sum1 + time_span1.count();
        //Search(exist in array)
        using namespace std::chrono;
        steady_clock::time_point t5 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            l.find(values[i]);
        }
        steady_clock::time_point t6 = steady_clock::now();
        duration<double>time_span3 = duration_cast<duration<double>>(t6 - t5);
        f << time_span3.count() << ",";
        sum2 = sum2 + time_span3.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t7 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            l.find(vals[i]);
        }
        steady_clock::time_point t8 = steady_clock::now();
        duration<double>time_span4 = duration_cast<duration<double>>(t8 - t7);
        f << time_span4.count() << ",";
        sum3 = sum3 + time_span4.count();
        //Delete
        using namespace std::chrono;
        steady_clock::time_point t3 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            l.is_erase(values[i]);
        }
        steady_clock::time_point t4 = steady_clock::now();
        duration<double>time_span2 = duration_cast<duration<double>>(t4 - t3);
        f << time_span2.count() << ","<<endl;
        sum4= sum4 + time_span2.count();
        

        f << "LinkedList(Sorted),";

                                               //linkedlist(sorted)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t9 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            ll.insert(values[i]);
        }
        steady_clock::time_point t10 = steady_clock::now();
        duration<double>time_span6 = duration_cast<duration<double>>(t10 - t9);
        f << time_span6.count() << ",";
        sum5 = sum5 + time_span6.count();
        //Search(exist in array)
        using namespace std::chrono;
        steady_clock::time_point t13 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            ll.find(values[i]);
        }
        steady_clock::time_point t14 = steady_clock::now();
        duration<double>time_span8 = duration_cast<duration<double>>(t14 - t13);
        f << time_span8.count() << ",";
        sum6= sum6 + time_span8.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t15 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            ll.find(vals[i]);
        }
        steady_clock::time_point t16 = steady_clock::now();
        duration<double>time_span9 = duration_cast<duration<double>>(t16 - t15);
        f << time_span9.count() << "," ;
        sum7 = sum7 + time_span9.count();
        //DELETE
        using namespace std::chrono;
        steady_clock::time_point t11 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            ll.remove(values[i]);
        }
        steady_clock::time_point t12 = steady_clock::now();
        duration<double>time_span7 = duration_cast<duration<double>>(t12 - t11);
        f << time_span7.count() << ","<<endl;
        sum8 = sum8 + time_span7.count();
        

        f << "LIST(STL),";
                                                         //list(stl)
         list<int>::iterator it;
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t17 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            lll.push_front(values[i]);
        }
        steady_clock::time_point t18 = steady_clock::now();
        duration<double>time_span10 = duration_cast<duration<double>>(t18 - t17);
        f << time_span10.count() << ",";
        sum9 = sum9 + time_span10.count();
        //Search(exist in array)
        using namespace std::chrono;
        steady_clock::time_point t21 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            find_in_stl_list(lll, values[i]);
        }
        steady_clock::time_point t22 = steady_clock::now();
        duration<double>time_span12 = duration_cast<duration<double>>(t22 - t21);
        f << time_span12.count() << ",";
        sum10 = sum10 + time_span12.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t23 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            find_in_stl_list(lll, vals[i]);
        }
        steady_clock::time_point t24 = steady_clock::now();
        duration<double>time_span13 = duration_cast<duration<double>>(t24 - t23);
        f << time_span13.count() << "," ;
        sum11 = sum11 + time_span13.count();
        //DELETE
        using namespace std::chrono;
        steady_clock::time_point t19 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            lll.remove(values[i]);
        }
        steady_clock::time_point t20 = steady_clock::now();
        duration<double>time_span11 = duration_cast<duration<double>>(t20 - t19);
        f << time_span11.count() << ","<<endl;
        sum12 = sum12 + time_span11.count();
       
        
        
        f << "BST(Iterative),";
                                                     //Bst(iterative)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t25= steady_clock::now();
        for (i = 0; i < s; i++)
        {
            b.insert(values[i]);

        }
        steady_clock::time_point t26 = steady_clock::now();
        duration<double>time_span14 = duration_cast<duration<double>>(t26 - t25);
        f << time_span14.count() << ",";
        sum13 = sum13 + time_span14.count();
        //Search(does exist in array)
        using namespace std::chrono;
        steady_clock::time_point t29 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            b.find(values[i]);
        }
        steady_clock::time_point t30 = steady_clock::now();
        duration<double>time_span16 = duration_cast<duration<double>>(t30 - t29);
        f << time_span16.count() << ",";
        sum14 = sum14 + time_span16.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t31 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            b.find(vals[i]);
        }
        steady_clock::time_point t32 = steady_clock::now();
        duration<double>time_span17 = duration_cast<duration<double>>(t32 - t31);
        f << time_span17.count() << "," ;
        sum15 = sum15 + time_span17.count();

        //DELETE
        using namespace std::chrono;
        steady_clock::time_point t27 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            b.erase(values[i]);
        }
        steady_clock::time_point t28 = steady_clock::now();
        duration<double>time_span15 = duration_cast<duration<double>>(t28 - t27);
        f << time_span15.count() << ","<<endl;
        sum16 = sum16 + time_span15.count();

       

        f << "BST(STL),";
        
                                                     //BST(Stl)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t33 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            p.first = values[i];
            p.second = values[i];
            m.insert(p);
        }
        steady_clock::time_point t34 = steady_clock::now();
        duration<double>time_span18 = duration_cast<duration<double>>(t34 - t33);
        f << time_span18.count() << ",";
        sum17 = sum17 + time_span18.count();
        //Search(exist in array)
        using namespace std::chrono;
        steady_clock::time_point t37 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            m.find(values[i]);
        }
        steady_clock::time_point t38 = steady_clock::now();
        duration<double>time_span20 = duration_cast<duration<double>>(t38 - t37);
        f << time_span20.count() << ",";
        sum18 = sum18 + time_span20.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t39 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            m.find(vals[i]);
        }
        steady_clock::time_point t40 = steady_clock::now();
        duration<double>time_span21 = duration_cast<duration<double>>(t40 - t39);
        f << time_span21.count() << "," ;
        sum19 = sum19 + time_span21.count();
        // DELETE
        using namespace std::chrono;
        steady_clock::time_point t35 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            m.erase(values[i]);
        }
        steady_clock::time_point t36 = steady_clock::now();
        duration<double>time_span19 = duration_cast<duration<double>>(t36 - t35);
        f << time_span19.count() << "," << endl;
        sum20 = sum20 + time_span19.count();
        

       
        f << "HASHTABLES(chaining through division),";

                                             //HashTables(chaining through divison
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t41 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            h.insert(values[i]);
        }
        steady_clock::time_point t42 = steady_clock::now();
        duration<double>time_span22 = duration_cast<duration<double>>(t42 - t41);
        f << time_span22.count() << ",";
        sum21 = sum21 + time_span22.count();
        //Search(exist in array) 
        using namespace std::chrono;
        steady_clock::time_point t45 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            h.find_h(values[i]);
        }
        steady_clock::time_point t46 = steady_clock::now();
        duration<double>time_span24 = duration_cast<duration<double>>(t46 - t45);
        f << time_span24.count() << ",";
        sum22 = sum22 + time_span24.count();
        //Search(does not exist in array) 
        using namespace std::chrono;
        steady_clock::time_point t47 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            h.find_h(vals[i]);
        }
        steady_clock::time_point t48 = steady_clock::now();
        duration<double>time_span25 = duration_cast<duration<double>>(t48 - t47);
        f << time_span25.count() << "," ;
        sum23 = sum23 + time_span25.count();
        //DELETE 
        using namespace std::chrono;
        steady_clock::time_point t43 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            h.erase_h(values[i]);
        }
        steady_clock::time_point t44 = steady_clock::now();
        duration<double>time_span23 = duration_cast<duration<double>>(t44 - t43);
        f << time_span23.count() << "," << endl;
        sum24 = sum24 + time_span23.count();
       



        f << "HashTables(chaining through multipication),";
       
                                         //HashTables(chaining through multipication)
        //INSERT 
            using namespace std::chrono;
            steady_clock::time_point t49 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            hh.insert(values[i]);
        }
        steady_clock::time_point t50 = steady_clock::now();
        duration<double>time_span26 = duration_cast<duration<double>>(t50 - t49);
        f << time_span26.count() << ",";
        sum25 = sum25 + time_span26.count();
        //Search(xist in array) 
        using namespace std::chrono;
        steady_clock::time_point t53 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hh.find_h(values[i]);
        }
        steady_clock::time_point t54 = steady_clock::now();
        duration<double>time_span28 = duration_cast<duration<double>>(t54 - t53);
        f << time_span28.count() << ",";
        sum26 = sum26 + time_span28.count();
        //Search(does not exist in array)
        using namespace std::chrono;
        steady_clock::time_point t55 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hh.find_h(vals[i]);
        }
        steady_clock::time_point t56 = steady_clock::now();
        duration<double>time_span29 = duration_cast<duration<double>>(t56 - t55);
        f << time_span29.count() << "," ;
        sum27 = sum27 + time_span29.count();
        //DELETE
        using namespace std::chrono;
        steady_clock::time_point t51 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            hh.erase_h(values[i]);
        }
        steady_clock::time_point t52 = steady_clock::now();
        duration<double>time_span27 = duration_cast<duration<double>>(t52 - t51);
        f << time_span27.count() << "," << endl;
        sum28 = sum28 + time_span27.count();


        f << "HashTables(openaddressing through linear probing),";

                                                 //HashTables(openaddressing through linear probing)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t57 = steady_clock::now();
        for (i = 0; i <s; i++)
        {
            hhh.insert(values[i]);
        }
        steady_clock::time_point t58 = steady_clock::now();
        duration<double>time_span30 = duration_cast<duration<double>>(t58 - t57);
        f << time_span30.count() << ",";
        sum29 = sum29 + time_span30.count();
        //Search(exist in array) 
        steady_clock::time_point t61 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.find(values[i]);
        }
        steady_clock::time_point t62 = steady_clock::now();
        duration<double>time_span32 = duration_cast<duration<double>>(t62 - t61);
        f << time_span32.count() << ",";
        sum30 = sum30 + time_span32.count();
        //Search(does not exist in array) 
        steady_clock::time_point t63 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.find(vals[i]);
        }
        steady_clock::time_point t64 = steady_clock::now();
        duration<double>time_span33 = duration_cast<duration<double>>(t64 - t63);
        f << time_span33.count() << ",";
        sum31 = sum31 + time_span33.count();
        //DELETE 
        steady_clock::time_point t59 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.erase(values[i]);
        }
        steady_clock::time_point t60 = steady_clock::now();
        duration<double>time_span31 = duration_cast<duration<double>>(t60 - t59);
        f << time_span31.count() << "," << endl;
        sum32 = sum32 + time_span31.count();



        f << "HashTables(openaddressing through Quadratic probing),";

                                                       //HashTables(openaddressing through quadratic probing)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t65 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            hhhh.insert(values[i]);
        }
        steady_clock::time_point t66 = steady_clock::now();
        duration<double>time_span34 = duration_cast<duration<double>>(t66 - t65);
        f << time_span34.count() << ",";
        sum33 = sum33 + time_span34.count();
        //Search(exist in array) 
        steady_clock::time_point t67 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhhh.find(values[i]);
        }
        steady_clock::time_point t68 = steady_clock::now();
        duration<double>time_span35 = duration_cast<duration<double>>(t68 - t67);
        f << time_span35.count() << ",";
        sum34 = sum34 + time_span35.count();
        //Search(does not exist in array) 
        steady_clock::time_point t69 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhhh.find(vals[i]);
        }
        steady_clock::time_point t70= steady_clock::now();
        duration<double>time_span36 = duration_cast<duration<double>>(t70 - t69);
        f << time_span36.count() << ",";
        sum35 = sum35 + time_span36.count();
        //DELETE 
        steady_clock::time_point t71 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhhh.erase(values[i]);
        }
        steady_clock::time_point t72 = steady_clock::now();
        duration<double>time_span37 = duration_cast<duration<double>>(t72 - t71);
        f << time_span37.count() << "," << endl;
        sum36 = sum36 + time_span37.count();


        f << "HashTables(openaddressing through DoubleHashing),";

        //HashTables(openaddressing through linear probing)
//INSERT
        using namespace std::chrono;
        steady_clock::time_point t73 = steady_clock::now();
        for (i = 0; i <s; i++)
        {
            hhh.insert(values[i]);
        }
        steady_clock::time_point t74 = steady_clock::now();
        duration<double>time_span38 = duration_cast<duration<double>>(t74 - t73);
        f << time_span38.count() << ",";
        sum37= sum37 + time_span38.count();
        //Search(exist in array) 
        steady_clock::time_point t75 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.find(values[i]);
        }
        steady_clock::time_point t76 = steady_clock::now();
        duration<double>time_span39 = duration_cast<duration<double>>(t76- t75);
        f << time_span39.count() << ",";
        sum38= sum38 + time_span39.count();
        //Search(does not exist in array) 
        steady_clock::time_point t77 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.find(vals[i]);
        }
        steady_clock::time_point t78 = steady_clock::now();
        duration<double>time_span40 = duration_cast<duration<double>>(t78-t77);
        f << time_span40.count() << ",";
        sum39 = sum39 + time_span40.count();
        //DELETE 
        steady_clock::time_point t79 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            hhh.erase(values[i]);
        }
        steady_clock::time_point t80 = steady_clock::now();
        duration<double>time_span41= duration_cast<duration<double>>(t80 - t79);
        f << time_span41.count() << "," << endl;
        sum40 = sum40 + time_span41.count();

        f << "HashTables(STL),";

                                                      //HashTables(STL)
        //INSERT
        using namespace std::chrono;
        steady_clock::time_point t81 = steady_clock::now();
        for (i = 0; i < s; i++)
        {
            pp.first = values[i];
            pp.second = values[i];
            mm.insert(pp);
        }
        steady_clock::time_point t82 = steady_clock::now();
        duration<double>time_span42 = duration_cast<duration<double>>(t82 - t81);
        f << time_span42.count() << "," ;
        sum41 = sum41 + time_span42.count();
        //Search(exist in array) 
        steady_clock::time_point t83 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            mm.find(values[i]);
        }
        steady_clock::time_point t84 = steady_clock::now();
        duration<double>time_span43 = duration_cast<duration<double>>(t84 - t83);
        f << time_span43.count() << ",";
        sum42 = sum42 + time_span43.count();
        //Search(does not exist in array) 
        steady_clock::time_point t85 = steady_clock::now();
        for (i = 0; i <ss; i++)
        {
            mm.find(vals[i]);
        }
        steady_clock::time_point t86 = steady_clock::now();
        duration<double>time_span44 = duration_cast<duration<double>>(t86 - t85);
        f << time_span44.count() << "," ;
        sum43 = sum43 + time_span44.count();
        //DELETE 
        steady_clock::time_point t87 = steady_clock::now();
        for (i = 0; i < ss; i++)
        {
            mm.erase(values[i]);
        }
        steady_clock::time_point t88 = steady_clock::now();
        duration<double>time_span45 = duration_cast<duration<double>>(t88 - t87);
        f << time_span45.count() << "," << endl;
        sum44 = sum44 + time_span45.count();
        f<< endl << endl;
    }
    av1 = sum1 / 10;
    av2 = sum2 / 10;
    av3 = sum3 / 10;
    av4 = sum4 / 10;
    av5 = sum5 / 10;
    av6 = sum6 / 10;
    av7 = sum7 / 10;
    av8 = sum8 / 10;
    av9 = sum9 / 10;
    av10 = sum10 / 10;
    av11 = sum11 / 10;
    av12 = sum12 / 10;
    av13 = sum13 / 10;
    av14 = sum14 / 10;
    av15 = sum15 / 10;
    av16 = sum16 / 10;
    av17 = sum17 / 10;
    av18 = sum18 / 10;
    av19 = sum19 / 10;
    av20 = sum20 / 10;
    av21 = sum21 / 10;
    av22 = sum22/ 10;
    av23= sum23 / 10;
    av24= sum24 / 10;
    av25= sum25/ 10;
    av26= sum26/ 10;
    av27= sum27/ 10;
    av28= sum28/ 10;
    av29= sum29/ 10;
    av30= sum30/ 10;
    av31 = sum31 / 10;
    av32 = sum32/ 10;
    av33= sum33/ 10;
    av34= sum34 / 10;
    av35= sum35 / 10;
    av36= sum36 / 10;
    av37= sum37 / 10;
    av38= sum38 / 10;
    av39= sum39 / 10;
    av40= sum40 / 10;
    av41= sum41 / 10;
    av42= sum42 / 10;
    av43= sum43 / 10;
    av44= sum44 / 10;
    f << endl << endl;
    f << "Averages of Functions:" << endl;
    f << ",INSERT,SEARCH(EXIST),SEARCH(DONT EXIST),DELETE" << endl;
    f << "LINKEDLIST(UNSORTED)," << av1 << "," << av2 << "," << av3 << "," << av4 << endl;
    f << "LINKEDLIST(SORTED)," << av5 << "," << av6 << "," << av7 << "," << av8 << endl;
    f << "LIST(STL)," << av9 << "," << av10 << "," << av11 << "," << av12 << endl;
    f << "BST(ITERATIVE)," << av13 << "," << av14 << "," << av15 << "," << av16 << endl;
    f << "BST(STL)," << av17 << "," << av18 << "," << av19 << "," << av20 << endl;
    f << "HASHTABLES(chaining through Division)," << av21 << "," << av22 << "," << av23 << "," << av24 << endl;
    f << "HASHTABLES(chaining through multipication)," << av25 << "," << av26 << "," << av27 << "," << av28 << endl;
    f << "HASHTABLES(openaddressing through linear probing)," << av29 << "," << av30 << "," << av31 << "," << av32 << endl;
    f << "HASHTABLES(openaddressing through Quadratic probing), " << av33 << ", " << av34 << ", " << av35 << ", " << av36 << endl;
    f << "HASHTABLES(openaddressing through Double-Hashing)," << av37 << "," << av38 << "," << av39 << "," << av40 << endl;
    f << "HASHTABLES(STL)," << av41 << "," << av42 << "," << av43 << "," << av44 << endl;
   
    return 0;
}