pkgname="openutils-sstring"
pkgver="1.7.0"
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
	"a7226c45a6ea42495f4dea34811064bfdf06f371dd3a5cdee343951852a3a5be1d56ddf130ab15a471046e26390005cd5595c11ebd74a484fdcc7a6c6008f08e"
	"aa847d067c67bec14f46b6ee4aa2404fb774f126f20a736497de2de0665134f57a32c615d74d5479f4ada8538f5c83183e94625276b2808661582dc5d52b5f6a"
	"6ecebe5630653a8bfcde5ae36e496db65cd117e6a7ead959bf7adcb2028a4d90f4a279891d50a971f24541062a08821adf3658964e5795b4cb80b97716a9794e"
	"c5633262224292305daa1218d1646c459569635765d8224424978a18560722a0fbf55145b1b3cad40c70fe8fceabb9f81d930a1addd8a84dae43fd6b2534067f"
	"b811b0f95efa53339fcbed64cd0a7fc36dd2458a56a9941db7ced844b4d7d6b3b76677923de5356aa15e3a42cda203fb5b02b3ea77110cc356e39bb231f0c2bf")

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
