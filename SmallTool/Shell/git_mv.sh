# git mv 批量操作

for file in $(ls | grep 'yours_source'); do git mv $file yours_destination; done;
