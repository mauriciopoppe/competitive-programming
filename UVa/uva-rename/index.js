#!/usr/bin/env node
const path = require('path')
const fs = require('fs')
const { promisify } = require('util')

const google = promisify(require('google'))
const $ = require('cheerio')
const request = require('request-promise-native')
const Case = require('case')
const Confirm = require('prompt-confirm')
const argv = require('yargs')
  .describe('s', 'skip search')
  .describe('r', 'back to old rename')
  .argv

function attempt (item) {
  const number = parseInt(item.title) || parseInt(item.describe)
  if (isNaN(number)) return false
  console.log(item)
  return number
}

async function search (term) {
  const r1 = await google(`${Case.title(term)} uva online judge`)
  const r2 = await google(`${term} uva online judge`)
  const res = [].concat(r1.links).concat(r2.links)

  let number
  res.forEach((link, i) => {
    if (!number) number = attempt(link)
  })
  return number
}

async function oldRename (filename, number) {
  const basename = path.basename(filename, '.cpp')
  const res = await google(`${Case.title(basename)} uva online judge`)
  const first = res.links[0]
  const content = await request(first.href)
  const ns = $.load(content)
  const title = ns('#col3 h3').text()
  return title + '.cpp'
}

async function newFormat (filename, number) {
  const basename = path.basename(filename, '.cpp')
  let googleNumber

  // skip google search
  if (!argv.s) {
    googleNumber = await search(basename)
  }

  let newName = Case.kebab(basename)
  if (newName[0] === '-') newName = newName.substr(1)
  if (number) {
    newName = `${number}.${newName}`
  }
  if (!isNaN(googleNumber)) {
    newName = `${googleNumber}.${newName}`
  }

  // if the filename starts with a number assume that it's the problem number
  const firstDashIndex = newName.search(/[^\d]/)
  const isInt = parseInt(newName.substr(0, firstDashIndex))
  if (!isNaN(isInt)) {
    const tok = newName.split('')
    tok[firstDashIndex] = '.'
    newName = tok.join('')
  }
  return newName + '.cpp'
}

async function rename (filename, number) {
  let newName
  if (argv.r) {
    newName = await oldRename(filename, number)
  } else {
    newName = await newFormat(filename, number)
  }
  const message = `rename file from "${filename}" to "${newName}"?`
  const execRename = await (new Confirm(message).run())
  if (execRename) {
    fs.renameSync(
      path.join(process.cwd(), filename),
      path.join(process.cwd(), newName)
    )
  }
}

async function main () {
  if (argv._.length > 0) {
    const filename = argv._[0]
    const number = argv._[1]
    await rename(filename, number)
    return
  }

  const fileNames = fs.readdirSync(process.cwd())
  for (let f of fileNames) {
    if (path.extname(f) === '.cpp') {
      await rename(f)
    }
  }
}

main()
