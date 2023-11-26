// 获取当前网页文本内容
var webpageText = document.body.innerText;

// 使用正则表达式匹配文本中的 magnet 链接
var magnetLinks = webpageText.match(/magnet:\?xt=urn:btih:[a-zA-Z0-9]*/g);

// 过滤重复的链接
if (magnetLinks && magnetLinks.length > 0) {
    // 使用 Set 来确保链接的唯一性
    var uniqueLinks = new Set(magnetLinks);
    // 将 Set 转换为数组，并格式化输出
    var uniqueLinksArray = Array.from(uniqueLinks);
    var formattedLinks = uniqueLinksArray.join('\n');
    console.log(formattedLinks);
} else {
    console.log('未找到磁力链接');
}
