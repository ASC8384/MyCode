// ==UserScript==
// @name         Redirect Arxiv to Papers Cool
// @namespace    ASC8384
// @version      0.1
// @description  redirect from arxiv to papers.cool
// @author       ASC_8384
// @match        https://arxiv.org/abs/*
// @grant        none
// @updateURL    https://github.com/ASC8384/MyCode/master/SmallTool/JavaScript/redirectArxiv2PapersCool.js
// ==/UserScript==

(function() {
    'use strict';

    var url = window.location.href;
    if (url.indexOf('https://arxiv.org/abs/') !== -1) {
        var paperId = url.split('https://arxiv.org/abs/')[1];
        var newUrl = 'https://papers.cool/arxiv/' + paperId;

        // 创建一个新的列表项
        var li = document.createElement('li');

        // 创建一个链接
        var link = document.createElement('a');
        link.href = newUrl;
        link.innerHTML = 'View on papers.cool';
        link.className = 'abs-button';

        // 将链接添加到新的列表项中
        li.appendChild(link);

        // 找到 "Access Paper" 下面的列表
        var ul = document.querySelector('.full-text ul');

        // 将新的列表项添加到列表的开始位置
        ul.insertBefore(li, ul.firstChild);
    }
})();
