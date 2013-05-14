module.exports = (grunt) ->
  cLintCB = (err, stdout, stderr, cb) ->
    if ///Lint!///.exec(stdout)
      grunt.warn(stdout)
    cb()

  files = ['main', 'init', 'ft245', 'power', 'uart']

  grunt.initConfig
    shell:
      gruntLint:
        command: 'coffeelint Gruntfile.coffee'
        options:
          stdout: false
          callback: cLintCB
      testLint:
        command: 'coffeelint -r test'
        options:
          stdout: false
          callback: cLintCB
      srcLint:
        command: 'splint -maintype -type src/*.c'
        options:
          stdout: true
          failOnError: true
      compile:
        command: 'emcc src/main.c src/init.c
         -o js/app.js -s INVOKE_RUN=0 -s LINKABLE=1
         --post-js util/post.js -s NAMED_GLOBALS=1 -s EXPORT_ALL=1
          --js-library util/library.js'
        options:
          stdout: true
          stderr: true
          failOnError: true
      sdcc1:
        command:
          files.map (a) ->
            'sdcc -c -ms08 --stack-loc 0x027F -o bin/ src/' + a + '.c'
          .join '&&'
        options:
          stdout: true
          stderr: true
          failOnError: true
      sdcc2_8:
        command:
          'sdcc -o bin/S08JS8 -ms08 --data-loc 0x80 --xram-loc 0x0100
          --xram-size 0x0180 --code-loc 0xE400 --code-size 0x1C00 ' +
          files.map (a) ->
            'bin/' + a + '.rel'
          .join ' '
        options:
          stdout: true
          stderr: true
          failOnError: true
      sdcc2_16:
        command:
          'sdcc -o bin/S08JS16 -ms08 --data-loc 0x80 --xram-loc 0x0100
          --xram-size 0x0180 --code-loc 0xC400 --code-size 0x3C00 ' +
          files.map (a) ->
            'bin/' + a + '.rel'
          .join ' '
        options:
          stdout: true
          stderr: true
          failOnError: true
      checksum_8:
        command:
          'srec_cat "(" bin/S08JS8.s37 -fill 0xff 0x0000 0xffff
            -crop 0xe400 0xffae 0xffc0 0x10000 -generate 0x100 0x102
            --b-e-constant 0x1b9d 2 ")"
            -big_endian_crc16 0xffb8 -xmodem -crop 0xffb8 0xffba
            -o bin/S08JS8.crc'
        options:
          stdout: true
          stderr: false
          failOnError: true
      checksum_16:
        command:
          'srec_cat "(" bin/S08JS16.s37 -fill 0xff 0x0000 0xffff
            -crop 0xc400 0xffae 0xffc0 0x10000 -generate 0x100 0x102
            --b-e-constant 0x1b9d 2 ")"
            -big_endian_crc16 0xffb8 -xmodem -crop 0xffb8 0xffba
            -o bin/S08JS16.crc'
        options:
          stdout: true
          stderr: false
          failOnError: true
      s19_8:
        command:
          'srec_cat -Header S08JS8_245
          bin/S08JS8.s37 bin/S08JS8.crc -o S08JS8.s19'
        options:
          stdout: true
          stderr: false
          failOnError: true
      s19_16:
        command:
          'srec_cat -Header S08JS16_245
          bin/S08JS16.s37 bin/S08JS16.crc -o S08JS16.s19'
        options:
          stdout: true
          stderr: false
          failOnError: true
      test:
        command: 'mocha --compilers coffee:coffee-script -r should -R spec'
        options:
          stdout: true
          stderr: true
          failOnError: true
    watch:
      gruntfile:
        files: 'Gruntfile.coffee'
        tasks: ['shell:gruntLint']
      tests:
        files: 'test/*.coffee'
        tasks: ['shell:testLint', 'shell:test']
      src:
        files: ['src/*.c', 'src/*.h']
        tasks: ['shell:srcLint', 'shell:compile', 'shell:test']


  grunt.loadNpmTasks 'grunt-contrib-watch'
  grunt.loadNpmTasks 'grunt-shell'

  grunt.registerTask 'test', ['shell']
  grunt.registerTask 'build_8', ['shell:sdcc1', 'shell:sdcc2_8',
   'shell:checksum_8', 'shell:s19_8']
  grunt.registerTask 'build_16', ['shell:sdcc1', 'shell:sdcc2_16',
   'shell:checksum_16', 'shell:s19_16']
  grunt.registerTask 'build', ['build_8', 'build_16']