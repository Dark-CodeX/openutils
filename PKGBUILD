pkgname="openutils-sstring"
pkgver="1.7.1"
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
	"1c0df2b7691d1bff2dfbe1f1fca19f437350ec67541ccb03e320befbf71081e0afb363d9a81f734447393e0e3fa59da94cdff4faa260c4e37b87a253a3e424c3"
	"7a061a36ec93478a581f696dc1618ba24d9dae4b5c07179b6b7f4574b8d5de2b7ceee940f16b1ffb7bc3fc4b23fb04c2c4d50135d88f7f2b29b10c267fe5172d"
	"f2872a363c81fce88131fe56053d8d5f81f3380a13a9e311e7b9c66c4908d6a51fbee5a7bd69eb6ee8af8690949bbb0f0872cf137e2b951d1642815114974a42"
	"7980056baf96408776f05d409c85f2587467618aed0560d7835f57da1e5369d715d469dece5aa0a08636d526e7022bf53d8548a7f28352974361afaaf7adb1fa"
	"52cf02181cf95fd6786d8691b5952ddb4e95af0cb32e0ef12e55c59cb072eb3b30a31fbc128cd0815d4cac95dfd06b88443cd9e446a141ab9f31af0a7c1488b0")

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
