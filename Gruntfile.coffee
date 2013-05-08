module.exports = (grunt) ->
  cLintCB = (err, stdout, stderr, cb) ->
    if ///Lint!///.exec(stdout)
      grunt.warn(stdout)
    cb()

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
      test:
        command: 'mocha --compilers coffee:coffee-script -r should'
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
        files: 'src/*.c'
        tasks: ['shell:srcLint', 'shell:compile', 'shell:test']


  grunt.loadNpmTasks 'grunt-contrib-watch'
  grunt.loadNpmTasks 'grunt-shell'

  grunt.registerTask 'test', ['shell']

class WringName
