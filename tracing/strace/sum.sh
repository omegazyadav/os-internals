
#!/bin/bash
function fun(){

sum=`expr $a + $b`

echo "The sum of two variable is : "$sum
}


read -p "Enter the number:" a
read -p "Enter the number:" b
fun
#sum=$(( $a + $b ))

# strace -ttT -o omega.log ./sum.sh
