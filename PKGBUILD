pkgname="openutils-sstring"
pkgver="2.1.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"cda6880df979dda86643c1db20f8cd1da21d05409ea5e93c9528120ee54b33209ead4ceed213b5e4461449646d87202de92fb80426e213b720226447314a5957"
	"6fa67850959b27363a61b3228d439b26a25a194b83324f802b5ace748ec79134135bc31666cb6c8de7b89c6e34d287091587852c0437337ec6932593ba6153aa"
	"a195319505679c1c73d10bf5e14910d1a63a2d087b563a1ccfc2614b4946673555e107316a261aeba056a1b52de3cf2b536bbf2312cda3378e9dc1b546cea8f9"
	"fcf874d3d13b26cd73094c841d4199c4a3a947ca8690a7e8b64f01d74ee4c6f33325fc8a72933d6e42b0d193a443275323c6e6649716dccc55d4560c7f830c97"
	"8ac9e356b8bc307240b0a2b142d43151eec9cf8a8fdea2fda80f6689a283d1785aeec4a816c65ab9301ce93d3b887b8bbef417da697c688de35c846445c3726e")

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
