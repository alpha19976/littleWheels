## STL数据结构
 STL数据结构[1] 以STL容器（Container）的形式提供，主要包括序列式容器（Sequence Containers）和关联式容器（Associative Containers）两大类。

#### 序列式容器
* array(build-in)：定长数组，C++内建
* vector
  * heap：以算法形式呈现，包含在STL算法中
     * priority-queue
* list
* slist：非STL标准
* deque
 * stack：配接器
 * queue：配接器 

#### 关联式容器
* RB-tree：非公开的，STL内部使用
 * set
 * map
 * multiset
 * multimap
* hashtable
 * hash-set
 * hash-map
 * hash-multiset
 * hash-multimap

以上列表中的层次关系代表容器间的内含关系，例如heap中内含一个vector，priority-queue中内含一个heap，set、map中都内含一个RB-tree。

## STL算法
STL算法[2]部分主要由头文件<algorithm>,<numeric>,<functional>组成。要使用 STL中的算法函数必须包含头文件<algorithm>，对于数值算法须包含<numeric>，<functional>中则定义了一些模板类，用来声明函数对象。

STL中算法大致分为四类：

* 1、非可变序列算法：指不直接修改其所操作的容器内容的算法。
* 2、可变序列算法：指可以修改它们所操作的容器内容的算法。
* 3、排序算法：包括对序列进行排序和合并的算法、搜索算法以及有序序列上的集合操作。
* 4、数值算法：对容器内容进行数值计算。

以下对所有算法进行细致分类并标明功能：
#### <一>查找算法(13个)：判断容器中是否包含某个值
* adjacent_find:            在iterator对标识元素范围内，查找一对相邻重复元素，找到则返回指向这对元素的第一个元素的ForwardIterator。否则返回last。重载版本使用输入的二元操作符代替相等的判断。
* binary_search:            在有序序列中查找value，找到返回true。重载的版本实用指定的比较函数对象或函数指针来判断相等。
* count:                    利用等于操作符，把标志范围内的元素与输入值比较，返回相等元素个数。
* count_if:                 利用输入的操作符，对标志范围内的元素进行操作，返回结果为true的个数。
* equal_range:              功能类似equal，返回一对iterator，第一个表示lower_bound，第二个表示upper_bound。
* find:                     利用底层元素的等于操作符，对指定范围内的元素与输入值进行比较。当匹配时，结束搜索，返回该元素的一个InputIterator。
* find_end:                 在指定范围内查找"由输入的另外一对iterator标志的第二个序列"的最后一次出现。找到则返回最后一对的第一个ForwardIterator，否则返回输入的"另外一对"的第一个ForwardIterator。重载版本使用用户输入的操作符代替等于操作。
* find_first_of:            在指定范围内查找"由输入的另外一对iterator标志的第二个序列"中任意一个元素的第一次出现。重载版本中使用了用户自定义操作符。
* find_if:                  使用输入的函数代替等于操作符执行find。
* lower_bound:              返回一个ForwardIterator，指向在有序序列范围内的可以插入指定值而不破坏容器顺序的第一个位置。重载函数使用自定义比较操作。
* upper_bound:              返回一个ForwardIterator，指向在有序序列范围内插入value而不破坏容器顺序的最后一个位置，该位置标志一个大于value的值。重载函数使用自定义比较操作。
* search:                   给出两个范围，返回一个ForwardIterator，查找成功指向第一个范围内第一次出现子序列(第二个范围)的位置，查找失败指向last1。重载版本使用自定义的比较操作。
* search_n:                 在指定范围内查找val出现n次的子序列。重载版本使用自定义的比较操作。

#### <二>排序和通用算法(14个)：提供元素排序策略
* inplace_merge:            合并两个有序序列，结果序列覆盖两端范围。重载版本使用输入的操作进行排序。
* merge:                    合并两个有序序列，存放到另一个序列。重载版本使用自定义的比较。
* nth_element:              将范围内的序列重新排序，使所有小于第n个元素的元素都出现在它前面，而大于它的都出现在后面。重载版本使用自定义的比较操作。
* partial_sort:             对序列做部分排序，被排序元素个数正好可以被放到范围内。重载版本使用自定义的比较操作。
* partial_sort_copy:        与partial_sort类似，不过将经过排序的序列复制到另一个容器。
* partition:                对指定范围内元素重新排序，使用输入的函数，把结果为true的元素放在结果为false的元素之前。
* random_shuffle:           对指定范围内的元素随机调整次序。重载版本输入一个随机数产生操作。
* reverse:                  将指定范围内元素重新反序排序。
* reverse_copy:             与reverse类似，不过将结果写入另一个容器。
* rotate:                   将指定范围内元素移到容器末尾，由middle指向的元素成为容器第一个元素。
* rotate_copy:              与rotate类似，不过将结果写入另一个容器。
* sort:                     以升序重新排列指定范围内的元素。重载版本使用自定义的比较操作。
* stable_sort:              与sort类似，不过保留相等元素之间的顺序关系。
* stable_partition:         与partition类似，不过不保证保留容器中的相对顺序。

#### <三>删除和替换算法(15个)
* copy:                     复制序列
* copy_backward:            与copy相同，不过元素是以相反顺序被拷贝。
* iter_swap:                交换两个ForwardIterator的值。
* remove:                   删除指定范围内所有等于指定元素的元素。注意，该函数不是真正删除函数。内置函数不适合使用remove和remove_if函数。
* remove_copy:              将所有不匹配元素复制到一个制定容器，返回OutputIterator指向被拷贝的末元素的下一个位置。
* remove_if:                删除指定范围内输入操作结果为true的所有元素。
* remove_copy_if:           将所有不匹配元素拷贝到一个指定容器。
* replace:                  将指定范围内所有等于vold的元素都用vnew代替。
* replace_copy:             与replace类似，不过将结果写入另一个容器。
* replace_if:               将指定范围内所有操作结果为true的元素用新值代替。
* replace_copy_if:          与replace_if，不过将结果写入另一个容器。
* swap:                     交换存储在两个对象中的值。
* swap_range:               将指定范围内的元素与另一个序列元素值进行交换。
* unique:                   清除序列中重复元素，和remove类似，它也不能真正删除元素。重载版本使用自定义比较操作。
* unique_copy:              与unique类似，不过把结果输出到另一个容器。

#### <四>排列组合算法(2个)：提供计算给定集合按一定顺序的所有可能排列组合
* next_permutation:         取出当前范围内的排列，并重新排序为下一个排列。重载版本使用自定义的比较操作。
* prev_permutation:         取出指定范围内的序列并将它重新排序为上一个序列。如果不存在上一个序列则返回false。重载版本使用自定义的比较操作。

#### <五>算术算法(4个)
* accumulate:               iterator对标识的序列段元素之和，加到一个由val指定的初始值上。重载版本不再做加法，而是传进来的二元操作符被应用到元素上。
* partial_sum:              创建一个新序列，其中每个元素值代表指定范围内该位置前所有元素之和。重载版本使用自定义操作代替加法。
* inner_product:            对两个序列做内积(对应元素相乘，再求和)并将内积加到一个输入的初始值上。重载版本使用用户定义的操作。
* adjacent_difference:      创建一个新序列，新序列中每个新值代表当前元素与上一个元素的差。重载版本用指定二元操作计算相邻元素的差。

#### <六>生成和异变算法(6个)
* fill:                     将输入值赋给标志范围内的所有元素。
* fill_n:                   将输入值赋给first到first+n范围内的所有元素。
* for_each:                 用指定函数依次对指定范围内所有元素进行迭代访问，返回所指定的函数类型。该函数不得修改序列中的元素。
* generate:                 连续调用输入的函数来填充指定的范围。
* generate_n:               与generate函数类似，填充从指定iterator开始的n个元素。
* transform:                将输入的操作作用与指定范围内的每个元素，并产生一个新的序列。重载版本将操作作用在一对元素上，另外一个元素来自输入的另外一个序列。结果输出到指定容器。

#### <七>关系算法(8个)
* equal:                    如果两个序列在标志范围内元素都相等，返回true。重载版本使用输入的操作符代替默认的等于操作符。
* includes:                 判断第一个指定范围内的所有元素是否都被第二个范围包含，使用底层元素的<操作符，成功返回true。重载版本使用用户输入的函数。
* lexicographical_compare:  比较两个序列。重载版本使用用户自定义比较操作。
* max:                      返回两个元素中较大一个。重载版本使用自定义比较操作。
* max_element:              返回一个ForwardIterator，指出序列中最大的元素。重载版本使用自定义比较操作。
* min:                      返回两个元素中较小一个。重载版本使用自定义比较操作。
* min_element:              返回一个ForwardIterator，指出序列中最小的元素。重载版本使用自定义比较操作。
* mismatch:                 并行比较两个序列，指出第一个不匹配的位置，返回一对iterator，标志第一个不匹配元素位置。如果都匹配，返回每个容器的last。重载版本使用自定义的比较操作。

#### <八>集合算法(4个)
* set_union:                构造一个有序序列，包含两个序列中所有的不重复元素。重载版本使用自定义的比较操作。
* set_intersection:         构造一个有序序列，其中元素在两个序列中都存在。重载版本使用自定义的比较操作。
* set_difference:           构造一个有序序列，该序列仅保留第一个序列中存在的而第二个中不存在的元素。重载版本使用自定义的比较操作。
* set_symmetric_difference: 构造一个有序序列，该序列取两个序列的对称差集(并集-交集)。

#### <九>堆算法(4个)
* make_heap:                把指定范围内的元素生成一个堆。重载版本使用自定义比较操作。
* pop_heap:                 并不真正把最大元素从堆中弹出，而是重新排序堆。它把first和last-1交换，然后重新生成一个堆。可使用容器的back来访问被"弹出"的元素或者使用pop_back进行真正的删除。重载版本使用自定义的比较操作。
* push_heap:                假设first到last-1是一个有效堆，要被加入到堆的元素存放在位置last-1，重新生成堆。在指向该函数前，必须先把元素插入容器后。重载版本使用指定的比较操作。
* sort_heap:                对指定范围内的序列重新排序，它假设该序列是个有序堆。重载版本使用自定义比较操作。

共70个算法。

### 参考资料
* [1]：4.1容器的概要与分类，《STL源码剖析》，侯捷.
* [2]：STL中的所有算法， http://www.cnblogs.com/nanke/archive/2011/05/10/2042662.html.
