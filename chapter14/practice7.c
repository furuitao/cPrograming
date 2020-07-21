/*
 * 7. 假定GENERIC_MAX是如下宏：
 * #define GENERIC_MAX(type)        \
 * type type##_max(type x, type y)  \
 * {                                \
 *   return x > y ? x : y;          \
 * }
 * (a) 写出GENERIC_MAX(long)被预处理器扩展后的形式。
 * (b) 解释为什么GENERIC_MAX不能应用于unsigned long这样的基本类型？
 * (c) 如何使GENERIC_MAX可以用于unsigned long这样的基本类型？提示：不要改变GENERIC_MAX的定义。
 */
#define GENERIC_MAX(type)        \
type type##_max(type x, type y)  \
{                                \
  return x > y ? x : y;          \
}


GENERIC_MAX(long)


typedef unsigned long Ulong;
GENERIC_MAX(Ulong)