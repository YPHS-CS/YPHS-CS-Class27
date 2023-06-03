const fs = require('fs');

// 遞歸函數遍歷目錄結構，輸出到README.md中
function generateReadme(path, level) {
  const files = fs.readdirSync(path);
  let output = '';
  let count = 0;
  level = level || 0;
  const indent = '  '.repeat(level); // 每一層的縮進

  files.forEach(function(file) {
    const stats = fs.statSync(path + '/' + file);
    if (stats.isDirectory()) {
      if(file.startsWith('.')) {
        return;
      }
      // 如果是資料夾，遞歸處理
      const result = generateReadme(path + '/' + file, level + 1);
      const folderCount = result.count;
      count += folderCount;
      output += indent + `- ${file} (${folderCount} files)\n${result.output}`;
    } else {
      // 如果是檔案，輸出檔名
      if (file.endsWith('.cpp') || file.endsWith('.py') || file.endsWith('.c')) {
        count++;
        output += indent + '  - ' + file + '\n';
      }
    }
  });

  return { output: output, count: count };
}

// 生成程式碼區塊
const result = generateReadme('./', 0);
const readmeContent = `
# Howard-OJ

###### 專門紀錄我的程式資料夾。

<details><summary>架構圖</summary>
<p>

\`總共完成了 ${result.count} 個題目。\`

\`\`\` 
${result.output}\`\`\`

</p>
</details>

`;

// 輸出目錄結構到README.md中
fs.writeFileSync('README.md', readmeContent);
