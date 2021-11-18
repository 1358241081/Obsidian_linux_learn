# 进度条函数
bar() {
# 用法: bar 1 10
#           ^----- 已经完成的百分比 (0-100).
#             ^--- 字符总长度.
((elapsed=$1*$2/100))

# 创建空格表示的进度条
printf -v prog  "%${elapsed}s"
printf -v total "%$(($2-elapsed))s"

printf '%s\r' "[${prog// /-}${total}]"
}
# 进度条使用示例
for ((i=0;i<=200;i++)); do
    # 纯粹的暂停动作 (为了本例可以更好的演示).
    (:;:) && (:;:) && (:;:) && (:;:) && (:;:)

    # Print the bar.
    bar "$i" "10"
done

printf '\n'
