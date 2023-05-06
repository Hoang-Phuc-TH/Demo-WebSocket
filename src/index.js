const express = require('express')
const morgan = require('morgan')
const { engine } = require('express-handlebars')
const path = require('path')
const exp = require('constants')
const app = express()
const port = 3000

const route = require('./routes')
//http logger
// app.use(morgan('combined'))

//Template engine
app.engine('hbs', engine({
    extname: '.hbs'
}));

app.set('view engine', 'hbs');
app.set('views', path.join(__dirname, 'resources/views'));

app.use(express.static(path.join(__dirname, 'public')))

app.use(express.urlencoded({ extended: true }));//middleware  gui tu html
app.use(express.json());// gui tu js

//XMLHTTPRequest , fetch m axios ,ajax 
// console.log('path: ', path.join(__dirname, 'resources/views'))
route(app);

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})