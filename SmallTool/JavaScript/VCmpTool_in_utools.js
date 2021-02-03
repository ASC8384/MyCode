if (ENTER.type === 'files') {
  const file = ENTER.payload
  // utools.showNotification(Object.keys(file[0]))
  const video1 = file[0].path
  const video2 = file[1].path
  require('child_process').spawn('start', ['cmd', '/k', `VCmpTool.exe "${video1}" "${video2}" && exit`], { shell: 'cmd.exe', detached: true })
}
