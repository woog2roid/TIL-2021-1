__자동으로 formatting을 해주는 VScode extentsion__
## 옵션
```prettierrc
{
    "singleQuote": ture,
    "semi": true,
    "useTabs": false,
    "tabWidth": 2,
    "trailingComma"": "all"
    "printWidth": 80
}
```
- singleQuote: "대신 '을 쓰는 옵션
- semi: 자동으로 ;이 붙여짐
- useTabs: 줄 들여쓰기를 탭과 함께함
- tabWidth: tab을 눌렀을 때 몇 칸이 띄어지는 지
- trailingComma: 객체 또는 배열이 여러줄로 있으면 ,를 붙여줌
- printWidth: 한 줄에 나타낼 수 있는 코드의 최대 길이
[Prettier 홈페이지](https://prettier.io/docs/en/options.html)

## 저장할 때 자동으로 코드 정리하기
윈도우 기준: File -> Preference -> Settings -> User -> Text Editor -> Formatting