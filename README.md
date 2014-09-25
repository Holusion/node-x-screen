node-x-screen
=============

Simple Utility to get X screen informations

require libx11-dev.

Currently only have 1 method :

###size()

send an object with 2 members :
  {width:x,height:y}

Get the total size of your X display. With 2 side to side 1080P screens, it'll be 3840*1080.
