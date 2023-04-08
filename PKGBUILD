pkgname="openutils-sstring"
pkgver="2.0.2"
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
	"4c3f3aaa151952cbee637cfc6f94ae2b0e5ce7ccab10a3058a0a74a1b8af3b2b84b474d583aa1e6a3258f287ca3380fd4c1848403b7b523aea820ce18399949c"
	"09c28563a21f917fb2983fd3cf8d40f570195c3522bfe758d7728505c638984a68da9686ccc30402f9bc71a0599367fc2822a7d069679fea4c16211c742f3952"
	"66f6902bed32f6300dd4208add1dd712801ddd916af8100d5e4ad74e04c9884cfba0132635e0ef3e596b82316668281ba504f4dcc76954d867919f2ac0b90fc4"
	"1621656ad683a6dadcd8a6a40e3a620d2a4ab2612c6c2a809b3c840a867cd52f0843e944373317a42365f5954befde31f13379e1856f4818464a86dea3c568c0"
	"2fc33094656e0bfb1a9defcbe52cedf491fb16cc0f8ba108c62f41f09b08a10727773ae5551f27dda5b1f06f796a3a08239f627231edc300b51478fe863b1a1e")

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
