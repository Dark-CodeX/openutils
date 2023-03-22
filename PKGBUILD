pkgname="openutils-sstring"
pkgver="1.7.2"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"88330fdee9a8e94cbcb18bcf20e4eacddfc5731cc270101e2c139e1d29832ba3541b8cd649b897eccfd60a5dbc83ece07dd2a44e9a2ca10da3b885d4abcc0c9c"
	"c312007334f198acf8fe304cb3fd3a280984c23d85af146acccc59ace29aabcb5310fc918c7515177ddf2281ab7aa5a1ee46ac83fd317378d40fb790369590b5"
	"a599276571256d57e7b7b59723ffe09d8eb5e806b3934fb1570076689d9bf55186cbff962e7a847fd3671091a269ce54d0034de8aaecbd7e4853c95bffbe4080"
	"79198134d8b88b06073556a89d1acca995f67184dcf9ba808ba0fb4ddb193e2c198c0f966de3e463aeed9a715f9cac826943d9eb68e651db1c421d27c13cdec4"
	"7c7c5d851949b7da71a58d1f3ee51e36226b64e03a5d32f05e8d50a5c0d25e92f06fd3d48a3e47c411724da1431f27a229b3ee326101321d315b6148fa04d080")

package() {
	echo "Memory Safe String Library in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
	cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
	cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
