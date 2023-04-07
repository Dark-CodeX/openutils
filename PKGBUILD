pkgname="openutils-date_time"
pkgver="1.0.1"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"8693cc873491c1e288022d884793260b70ecbdc9acd37a283479a63494d00696684f320817acc1108657b7f9bcb3763420d791c4500feda538c5c46f7d1d30c4"
	"398d1ceb2333e5961b5b8313c17a4b092bfc446ade5f4e2327e80cf5608da2fbccdbaaa18021a5c94aeaf124572de12a3a1421c311e950198354a57d2e342107")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
