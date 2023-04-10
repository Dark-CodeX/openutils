pkgname="openutils-sstring"
pkgver="2.1.5"
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
	"1b3f5562d0a876906ae891f7eb7661981f43c58083e067adc25ad9aa261defff853ea004dcfd319b59c04a2789954d95e246d6af32febd0e0a6b730b7681ea30"
	"9b1e247d7d216d64b89430a4d80af7d30778d64678203d0329c66556cb5709643a28398025b89868ccc9993800e4d5c68d786255e1bb0efadd63f90e712e59cf"
	"f59ef251ea8b9c3bf67fb9c0cbe9c1c62226fa2999db0a99fcda3cbbf9983f1d29f1723cc3db9d0c596c6c8c4d39e506d33ed657d76e976fd2f6a704dab062ea"
	"d8ca3df37f8d8258172582cf68df4a753d82782d54a59ec3fde35974baccc796de4099af0c47de450ea624d19220caac02c83c99e29b3176dcb344feea3f58c3"
	"ca24326299539643d2f09c02994ca5f73ca845af815126cba18902ed9f4d2c227cb93fb564a3b1373c8007cdb4afcc020155006f1395b4d9533f87af03d41615")

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
