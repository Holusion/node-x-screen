{
  "targets": [
    {
      "target_name": "xscreen",
      "sources": [ "src/main.cc" ],
      'link_settings': {
          'libraries': [
              '-lX11'
          ]
      }
    }
  ]
}
