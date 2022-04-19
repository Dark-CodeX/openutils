pkgname="openutils-sstring"
pkgver="1.6.9"
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
	"3dfe22f0786526f539d3ec03da1fd929db4e1b55305132eb50ec496fdd49d0848466f29e4966649bd3935814da92392e9b4768c9a71849fb39abf9d8c37a2e12"
	"b93dd999fed8c2d978538d789107641c7ffe1bc44f161278c588ad8002ecd3e8bee80770cc25b6f9f3850f88ba0015580d3e18616c73428abd2e9573b044cf42"
	"70b329a5dbe8deb7902bf583a271f94e610c0005905081583673389a0bfc82d0eb8259055080d880963bac94ec4758c263bb424c78558f06b7cf6f408f024b8f"
	"339f5baa0932d6689423635dafa954d8a439d66402164c13da6ada3f1f5355a1bcf4d69b7138a7e3dfa15500ecc3ee2d3f0420185e1fe9574b0acb75223e5ef8"
	"fc408bd0aec276813e509441502204ba6e9b0002d41db5e5add056357b14ea3a9fa0a988e847f3457f1dd2ee55fafa2b3f104ed905cea44c4979f25936f16a55")

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
