{
  "targets": [
    {
      "target_name": "xscreen",
      "variables":{
        'HAVE_X11':'<!(pkg-config --exists x11d && echo true ||echo false)'
      },
      "conditions":[
        ['HAVE_X11=="true"',{
          "defines":["HAVE_X11"],
          'link_settings': {
              'libraries': [
                  '!@(pkg-config --libs x11)'
              ]
          },
          "sources": [ "src/main.cc" ],
        },{ #doesn't have x11 lib available
          "sources": [ "src/nox.cc" ],
        }]
      ]
    }
  ]
}
