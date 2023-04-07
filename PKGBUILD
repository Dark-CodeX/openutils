pkgname="openutils-sstring"
pkgver="2.0.0"
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
	"89c0ddb506f635681c9a5d2f2360ea49fb7dee303d7e4eed31aef0fa866414420777030fb6c63567c6abae874d73e23cbdd6bce852064a1586434938384c0efc"
	"17851421473bc2471e7751b5e137b448406f56a1463d4fa8f03a57e498d5acae6c0bd1fd89c924226e6805af4bd1e0ecebf704ac4a1dc733f86fdbd2d9b8c5ed"
	"337b77c237005c22c5fc08838c657e5a028d8f14ee5f4f5415b825cef59e0255a8e1f71a27d796a00971f127a37ef8ffd779f175e97aad7910fa2cf8d6c6d7f3"
	"e9bf0ac0215a50becb8a4c8a041660d3137239a753046b643042c7cf0dacec9fa77ceb86528a1418cf1a868dd4c9b552db08dc0e46060b715fdcdb7d4e23f9a2"
	"cd1596aa84ab562df58948042846ec7a294c4a79de566118595ef3d4c3122af16495326b824b1ea0edd7a964955cf882e802bb561c2e2b6993e10adfe98d00c3")

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
