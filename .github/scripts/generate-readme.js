const fs = require('fs');

// 遞歸函數遍歷目錄結構，輸出到README.md中
function generateReadme(path, level, count = 0) {
  const files = fs.readdirSync(path);
  let output = '';
  level = level || 0;
  const indent = '  '.repeat(level);

  files.forEach(function(file) {
    const stats = fs.statSync(path + '/' + file);
    if (stats.isDirectory()) {
      if(file.startsWith('.')) {
        return;
      }
      const result = generateReadme(path + '/' + file, level + 1);
      const numCppFiles = result.count;
      count += numCppFiles;
      const countStr = numCppFiles ? ` (${numCppFiles} files)` : '';
      output += `${indent}- ${file}${countStr}\n${result.output}`;
    } else if (file.endsWith('.cpp') || file.endsWith('.py') || file.endsWith('.c')) {
      count++;
      output += `${indent}- ${file}\n`;
    }
  });

  return { output: output, count: count };
}

const result = generateReadme('./', 0);
const readmeContent = `
# Howard-OJ

###### 專門紀錄我的程式資料夾。

\`總共完成了 ${result.count} 個題目。\`

\`\`\` 
${result.output}\`\`\`
`;

fs.writeFileSync('README.md', readmeContent);



// 生成程式碼區塊
const result = generateReadme('./', 0);
const readmeContent = `
# Howard-OJ

###### 專門紀錄我的程式資料夾。

\`總共完成了 ${result.count} 個題目。\`

\`\`\` 
${result.output}\`\`\`
`;

// 輸出目錄結構到README.md中
fs.writeFileSync('README.md', readmeContent);
